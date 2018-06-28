#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int wed = 6;
const int N = 101;

class Cell {
public:
	Cell() {

	}
	Cell(char con[]) {

	}
	~Cell() {

	}
	void show() {

	}
private:
	string content;
};

class Table {
public:
	Table() {
		row = col = strlen(table[0][0]);
		memset(table, 0, sizeof(table));
		row_list[0] = col_list[0] = 0;
	}
	Table(int row, int col) {
		this->row = row, this->col = col;
		memset(table, 0, sizeof(table));
		for (int i = 0; i < row; i++)
			row_list[i] = i + 1;
		for (int j = 0; j < col; j++)
			col_list[j] = j + 1;
		row_list[row] = col_list[col] = 0;
	}
	void set(int row, int col, int mesg) {
		int loc_row = row_list[0], loc_col = col_list[0];
		for (int count = 0; count < row - 1; count++)
			loc_row = row_list[loc_row];
		for (int count = 0; count < col - 1; count++)
			loc_col = col_list[loc_col];
		_itoa(mesg, table[loc_row][loc_col], 10);
	}
	void set(int row, int col, const char mesg[]) {
		int loc_row = row_list[0], loc_col = col_list[0];
		for (int count = 0; count < row - 1; count++)
			loc_row = row_list[loc_row];
		for (int count = 0; count < col - 1; count++)
			loc_col = col_list[loc_col];
		strcpy(table[loc_row][loc_col], mesg);
	}
	void show() {
		if (!(row * col)) {
			cout << "表格为空" << endl << endl;
			return;
		}
		for (int i = 0; i < col; i++) for (int h = 0; h <= wed; h++) cout << "-";
		cout << "----" << endl << "Row/Col ";
		for (int h = 1; h <= col; h++) {
			cout << h;
			for (int g = 0; g < wed; g++) cout << " ";
		}
		cout << endl;
		int row_con = 1;
		for (int i = row_list[0]; i; i = row_list[i]) {
			cout << endl << "   " << row_con++ << "   ";
			for (int j = col_list[0]; j; j = col_list[j]) {
				cout << table[i][j];
				for (int g = 0; g <= wed - strlen(table[i][j]); g++)
					cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < col; i++) for (int h = 0; h <= wed; h++) cout << "-";
		cout << "----" << endl << endl;
	}
	void addRow() {
		for (int i = row_list[0]; ; i = row_list[i])
			if (!row_list[i]) {
				row_list[i] = row + 1;
				row_list[++row] = 0;
				break;
			}
	}
	void delRow(int n) {
		int count = 0, loc = 0;
		for (loc = 0; count < n - 1; loc = row_list[loc]) count++;
		row_list[loc] = row_list[row_list[loc]];
	}
	void addColumn() {
		for (int i = col_list[0]; ; i = col_list[i])
			if (!col_list[i]) {
				col_list[i] = col + 1;
				col_list[++col] = 0;
				break;
			}
	}
	void delColumn(int n) {
		int count = 0, loc = 0;
		for (loc = 0; count < n - 1; loc = col_list[loc]) count++;
		col_list[loc] = col_list[col_list[loc]];
	}
	~Table() {
		memset(table, 0, sizeof(table));
	}
private:
	Cell cells;
	int row;
	int col;
	char table[N][N][N];
	int row_list[N];
	int col_list[N];
};

int main() {
	Table tb;
	tb.show();
	tb.addRow();
	tb.show();
	tb.addColumn();
	tb.show();
	Table tb1(5, 5);
	tb1.show();
	tb1.set(1, 1, 30);
	tb1.set(2, 2, "hello");
	tb1.show();
	tb1.delRow(1);
	tb1.show();
	tb1.delColumn(1);
	tb1.show();
	return 0;
}
