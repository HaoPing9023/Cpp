#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// --- 数据结构定义 ---

// 院系信息
struct Department {
    int id;             // 编号
    string name;        // 名称
    string address;     // 地址
};

// 校友信息
struct Alumni {
    int id;             // 编号
    int depId;          // 所属院系编号
    string name;        // 姓名
    int gradYear;       // 毕业年份
    string phone;       // 联系方式
};

// 全局数据容器
vector<Department> depts;
vector<Alumni> alumniList;

// --- 初始化数据 ---
void initData() {
    // 初始化院系 (表1)
    depts.push_back({ 1, "计算与信息科学学院", "1号楼" });
    depts.push_back({ 2, "应用科学与工程学院", "3号楼" });
    depts.push_back({ 3, "商学院", "2号楼" });

    // 初始化校友 (表2)
    alumniList.push_back({ 1, 1, "张三", 2010, "18899997777" });
    alumniList.push_back({ 2, 2, "李四", 2014, "19988886666" });
    alumniList.push_back({ 3, 1, "王五", 2005, "13366663333" });
    alumniList.push_back({ 4, 3, "赵六", 2018, "17733332222" });
    alumniList.push_back({ 5, 3, "钱七", 2013, "16688889999" });
}

// 辅助函数：打印校友列表
void printAlumniList() {
    cout << "ID\t姓名\t年份\t院系ID\t联系方式" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < alumniList.size(); i++) {
        cout << alumniList[i].id << "\t"
            << alumniList[i].name << "\t"
            << alumniList[i].gradYear << "\t"
            << alumniList[i].depId << "\t"
            << alumniList[i].phone << endl;
    }
    cout << "----------------------------------------" << endl;
}

// --- 核心算法实现 ---

// 1. 排序算法：冒泡排序 (Bubble Sort)
// 参数 ascending: true为升序, false为降序
void bubbleSortByYear(bool ascending) {
    int n = alumniList.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            bool condition;
            if (ascending) {
                // 升序：如果前者大于后者，交换
                condition = alumniList[j].gradYear > alumniList[j + 1].gradYear;
            }
            else {
                // 降序：如果前者小于后者，交换
                condition = alumniList[j].gradYear < alumniList[j + 1].gradYear;
            }

            if (condition) {
                Alumni temp = alumniList[j];
                alumniList[j] = alumniList[j + 1];
                alumniList[j + 1] = temp;
            }
        }
    }
}

// 2. 查找算法：二分查找 + 线性校验 (Binary Search)
// 先用二分法找到对应的年份，再检查姓名是否匹配
// 注意：必须在升序排序后使用
void searchByYearAndName(int targetYear, string targetName) {
    int left = 0;
    int right = alumniList.size() - 1;
    bool found = false;
    int foundIndex = -1;

    // 第一步：二分查找年份
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (alumniList[mid].gradYear == targetYear) {
            foundIndex = mid;
            break; // 找到了该年份的一个记录
        }
        else if (alumniList[mid].gradYear < targetYear) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // 第二步：由于可能有多人同一年毕业，需要向左右扩散查找匹配姓名的人
    if (foundIndex != -1) {
        // 向左扫描
        int i = foundIndex;
        while (i >= 0 && alumniList[i].gradYear == targetYear) {
            if (alumniList[i].name == targetName) {
                cout << "查找成功！校友信息如下：" << endl;
                cout << "姓名: " << alumniList[i].name
                    << ", 年份: " << alumniList[i].gradYear
                    << ", 电话: " << alumniList[i].phone << endl;
                found = true;
            }
            i--;
        }
        // 向右扫描
        i = foundIndex + 1;
        while (i < alumniList.size() && alumniList[i].gradYear == targetYear) {
            if (alumniList[i].name == targetName) {
                cout << "查找成功！校友信息如下：" << endl;
                cout << "姓名: " << alumniList[i].name
                    << ", 年份: " << alumniList[i].gradYear
                    << ", 电话: " << alumniList[i].phone << endl;
                found = true;
            }
            i++;
        }
    }

    if (!found) {
        cout << "查找失败：未找到年份为 " << targetYear << " 且姓名为 " << targetName << " 的校友。" << endl;
    }
}

// 3. 统计功能：根据院系编号统计
void statByDept(int targetDeptId) {
    int count = 0;
    string deptName = "未知院系";

    // 获取院系名称
    for (int i = 0; i < depts.size(); i++) {
        if (depts[i].id == targetDeptId) {
            deptName = depts[i].name;
            break;
        }
    }

    // 遍历统计
    for (int i = 0; i < alumniList.size(); i++) {
        if (alumniList[i].depId == targetDeptId) {
            count++;
        }
    }

    cout << "统计结果：" << deptName << " (编号" << targetDeptId << ") 共有校友 " << count << " 人。" << endl;
}

int main() {
    initData();

    cout << "=== 原始校友列表 ===" << endl;
    printAlumniList();

    // --- 任务1：排序展示 ---
    cout << "\n=== 任务1：按毕业年份升序排序 (使用冒泡排序) ===" << endl;
    bubbleSortByYear(true); // true表示升序
    printAlumniList();

    // --- 任务2：组合查找 ---
    cout << "\n=== 任务2：查找操作 (使用二分查找) ===" << endl;
    // 案例：查找 2013年毕业的 钱七
    searchByYearAndName(2013, "钱七");
    // 案例：查找 2010年毕业的 李四 (不存在的组合)
    searchByYearAndName(2010, "李四");

    // --- 任务3：统计操作 ---
    cout << "\n=== 任务3：院系校友统计 ===" << endl;
    statByDept(3); // 统计商学院(ID=3)
    statByDept(1); // 统计计信院(ID=1)

    return 0;
}