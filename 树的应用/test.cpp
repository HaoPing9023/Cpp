#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // 用于格式化输出

using namespace std;

// --- 数据结构定义 ---

// 1. 定义叶子结点：校友信息
struct Alumni {
    int id;             // 编号
    string name;        // 姓名
    int gradYear;       // 毕业年份
    string phone;       // 联系方式
};

// 2. 定义分支结点：院系信息
// 每个院系结点包含一个校友列表（相当于树的孩子结点）
struct Department {
    int id;             // 院系编号
    string name;        // 院系名称
    string address;     // 地址
    vector<Alumni> children; // 存储该院系下的校友（孩子结点）
};

// 全局变量，模拟整棵树（根节点下的子树集合）
vector<Department> schoolTree;

// --- 功能函数实现 ---

// 初始化数据：根据实验报告中的表1和表2构建树
void initData() {
    // 1. 创建院系结点 (树的第一层)
    Department d1 = { 1, "计算与信息科学学院", "1号楼", {} };
    Department d2 = { 2, "应用科学与工程学院", "3号楼", {} };
    Department d3 = { 3, "商学院", "2号楼", {} };

    // 2. 将校友插入对应的院系 (树的第二层)
    // 根据表2的数据，将校友分配到对应的院系ID中

    // 院系1的学生
    d1.children.push_back({ 1, "张三", 2010, "18899997777" });
    d1.children.push_back({ 3, "王五", 2005, "13366663333" });

    // 院系2的学生
    d2.children.push_back({ 2, "李四", 2014, "19988886666" });

    // 院系3的学生
    d3.children.push_back({ 4, "赵六", 2018, "17733332222" });
    d3.children.push_back({ 5, "钱七", 2013, "16688889999" });

    // 将构建好的院系挂载到树上
    schoolTree.push_back(d1);
    schoolTree.push_back(d2);
    schoolTree.push_back(d3);
}

// 树形展示：按层次输出 院系 -> 校友
void displayTree() {
    cout << "============= 校友通讯录树形展示 =============" << endl;
    // 遍历第一层：院系
    for (int i = 0; i < schoolTree.size(); i++) {
        cout << "+-- [" << schoolTree[i].id << "] " << schoolTree[i].name
            << " (" << schoolTree[i].address << ")" << endl;

        // 遍历第二层：该院系下的校友
        if (schoolTree[i].children.empty()) {
            cout << "    |-- (暂无校友信息)" << endl;
        }
        else {
            for (int j = 0; j < schoolTree[i].children.size(); j++) {
                Alumni stu = schoolTree[i].children[j];
                cout << "    |-- " << stu.name
                    << "\t[毕业:" << stu.gradYear
                    << " | 电话:" << stu.phone << "]" << endl;
            }
        }
        cout << "|" << endl; // 空行分隔
    }
    cout << "==============================================" << endl;
}

// 查找功能：在树中搜索特定姓名的校友
void searchAlumni(string targetName) {
    bool found = false;
    cout << "\n正在查找校友: " << targetName << " ......" << endl;

    // 遍历整个树结构进行查找
    for (int i = 0; i < schoolTree.size(); i++) { // 遍历院系
        for (int j = 0; j < schoolTree[i].children.size(); j++) { // 遍历校友
            if (schoolTree[i].children[j].name == targetName) {
                // 找到了，输出完整路径信息
                Alumni stu = schoolTree[i].children[j];
                cout << "----------------------------------" << endl;
                cout << "查找成功！详细信息如下：" << endl;
                cout << "姓名: " << stu.name << endl;
                cout << "所属院系: " << schoolTree[i].name << endl; // 父结点信息
                cout << "院系地址: " << schoolTree[i].address << endl;
                cout << "毕业年份: " << stu.gradYear << endl;
                cout << "联系方式: " << stu.phone << endl;
                cout << "----------------------------------" << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "未找到名为 \"" << targetName << "\" 的校友信息。" << endl;
    }
}

int main() {
    // 1. 初始化数据
    initData();

    // 2. 展示树形结构
    displayTree();

    // 3. 模拟查找操作
    // 案例1：查找存在的校友
    searchAlumni("张三");

    // 案例2：查找另一个存在的校友
    searchAlumni("钱七");

    // 案例3：查找不存在的校友
    searchAlumni("孙悟空");

    // 为了防止窗口直接关闭（可选）
    // system("pause"); 
    return 0;
}