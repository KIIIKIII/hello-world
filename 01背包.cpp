#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int maxn = 1001;     //规定max(num, weight_total) <= maxn
int Dp_data[maxn][maxn];   //记录dp的结果 以num为行数, weight_total为列数
int Dp_direct[maxn][maxn]; //记录dp的路径 以num为行数, weight_total为列数
int max_vale;
vector<int> direct; 	   //存储最优路径

struct Object{
	int vale;
	int weight;
} Object[maxn];

/**
 * @brief 将指定的二维数组显示出来
 */
void show(int canvas[maxn][maxn], int row, int col) {
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++)
			cout << setw(3) << canvas[i][j];
		cout << endl;
	}
}

void D_p(int num, int weight_total) {
	/*  下面双重循环是具体的dp过程  */
	/*  第一重循环 从0开始对行进行循环 上限是num - 1*/
	for (int row = 0; row < num; row ++) {
		/*   第二重循环 从0开始对列进行循环 上限是weight_total */
		for (int col = 0; col <= weight_total; col ++) {
			/**
			 * 以第row件物品做待选时候Dp_data[row][]这一行表示所有的可能状态
			 * col表示以第row件物品做待选时选中了某些物品之后还剩下的余重
			 * 判断条件: 满足所有判断条件之后在row, col位置选中第row个物品
			 * 		1)	选中第row个物品时没有超载
			 * 		2) 	选中这个物品之后的总价值比选中这个物品之后余重位置对应的价值要大
			 */
			if ((col - Object[row].weight >= 0 && Object[row].vale + Dp_data[row][col] > Dp_data[row][col - Object[row].weight])) {
				/*  过程显示  */
				cout << "条件满足: " << "front_col-"  << col << " front_Dp_data-" << Dp_data[row][col] << ";";
				cout << "正在修改: row-" << row << " col-" << col - Object[row].weight;
				cout << " Dp_data:" << Dp_data[row][col - Object[row].weight] << "->" << Object[row].vale + Dp_data[row][col];
				cout << " Dp_direct:" << Dp_direct[row][col - Object[row].weight] << "->" << col << endl;

				/*  实际操作  */
				/*  记录选择的路径到Dp_direct中 */
				Dp_direct[row][col - Object[row].weight] = col;
				Dp_direct[row + 1][col - Object[row].weight] = col - Object[row].weight;
				/*  在选中第row个物品的对应col及col - Object[row].weight位置记录总价值, 并将这个数字赋值给row+1的对应位置上*/
				Dp_data[row][col - Object[row].weight] = Object[row].vale + Dp_data[row][col];
				Dp_data[row + 1][col - Object[row].weight] = Object[row].vale + Dp_data[row][col];
			}
		}
	}

/********************************************************/
	/*   显示Dp存储的二维数组内容   */
	cout << "Dp_data:" << endl;
	show(Dp_data, num, weight_total);
	cout << "Dp_direct:" << endl;
	show(Dp_direct, num, weight_total);\
/********************************************************/

	/*  在Dp_data的最后一行及第num - 1行寻找所存的最大数据即为最大的价值  */
	int loc = 0;
	for (int col = 0; col < weight_total; col ++) {
		if (max_vale < Dp_data[num - 1][col]) {
			max_vale = Dp_data[num - 1][col];
			cout << "max:" << max_vale << endl;
			loc = col;   //记录位置
		}
	}

	/*  利用最大价值的loc配合Dp_direct找出这条最优解的选择路径并记录在direct中 */
	for (int row = num - 1; row >= 0; row --) {
		if (loc != Dp_direct[row][loc])
			direct.push_back(row);
		loc = Dp_direct[row][loc];
		if (loc == weight_total) break;
	}

	/*  结论输出  */
	cout << "__________________________________________" << endl;
	cout << "共选择" << direct.size() << "件物品:" << endl;
	int vale_now = 0, weight_now = 0;
	while (direct.begin() != direct.end()) {
		vale_now += Object[direct.back()].vale;
		weight_now += Object[direct.back()].weight;
		cout << "选择第" << direct.back() + 1 << "个物品; 此时总价值:" << vale_now << "; 此时总重量: " << weight_now << endl;
		direct.pop_back();
	}

	for (vector<int>::iterator it = direct.end() - 1; it != direct.begin() - 1; it --) {
		vale_now += Object[*it].vale;
		weight_now += Object[*it].weight;
		cout << "选择第" << *it + 1 << "个物品; 此时总价值:" << vale_now << "; 总重量: " << weight_now << endl;
	}
	cout << "最后最大价值: " << max_vale << "; 总重量: " << weight_now << endl;
}

int main() {
//	#ifdef DEBUG
//	freopen("01bag.txt", "r", stdin);
//	#endif
	int num = 0, weight_total = 0;   //物品数量num, 总重量(int型)weight_total
	cout << "输入背包的最大载重量和物品的总数: ";
	cin >> weight_total >> num;
	for (int i = 0; i < num; i ++) {
		cout << "输入第" << i + 1 << "个物品的价值和重量: ";
		cin >> Object[i].weight >> Object[i].vale;
	}
	cout << "__________________________________________" << endl;
	D_p(num, weight_total);   //进行dp过程

	return 0;
}
