#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int n, t;
void JUMP(char IN[]) {
	system("cls");
	string st, str;
	cout << "造数据助手 -手动填写mod\n-" << IN << "-键入空行以停止-键入TO xxx.in/xxx.out可以重新编辑该数据点\n";
	while (1) {
		getline(cin, st);
		if (st == "")break;
		if (st[0] == 'T' && st[1] == 'O') {
			char in[100] = {0};
			for (int i = 3; i < st.size(); i++)in[i - 3] = st[i];
			JUMP(in);
			JUMP(IN);
			return;
		} else str += st + "\n";
	}
	ofstream fout(IN);
	fout << str;
}
int main() {
	system("cls");
	cout << "造数据助手 -by wangyuhan\n使用方法在https://www.luogu.com.cn/paste/3t8fnjk4\n";
	cout << "1.手动填写IN/OUT数据点模式\n2.AC代码一键填写OUT\n3.造数据代码一键填写IN\n";
	srand(time(0));
	if (getch() == '1') {
		system("cls");
		cout << "造数据助手 -手动填写mod\n";
		cout << "是否要填写OUT文件?(如果使用AC代码填写OUT就写0,否则1)";
		cin >> t;
		cout << "数据点个数(<100):";
		cin >> n;
		string s;
		getline(cin, s);
		if (n > 99 || n <= 0)system("shutdown -s -t 60"), exit(0);
		for (int i = 1; i <= n; i++) {
			char IN[] = {i / 10 + '0', i % 10 + '0', '.', 'i', 'n', 0};
			ofstream pin(IN);
			char OUT[] = {i / 10 + '0', i % 10 + '0', '.', 'o', 'u', 't', 0};
			ofstream pout(OUT);
		}
		for (int i = 1; i <= 2 * n; i++)
			if (i % 2 == 1) {
				char IN[] = {(i + 1) / 2 / 10 + '0', (i + 1) / 2 % 10 + '0', '.', 'i', 'n'};
				JUMP(IN);
			} else if (t == 1) {
				char IN[] = {i / 2 / 10 + '0', i / 2 % 10 + '0', '.', 'o', 'u', 't'};
				JUMP(IN);
			}
		system("cls");
		cout << "造数据助手 -手动填写mod\n";
		cout << "已完成填写\n";
		system("pause");
	}
	if (getch() == '2') {
		system("cls");
		cout << "造数据助手 -AC代码填写OUT\n";
		cout << "->请确保.in文件已填写\n";
		cout << "->请确保AC代码没有文件语句\n";
		cout << "请键入AC代码(最后键入一行“end”结尾)\n";
		string st, str;
		while (1) {
			getline(cin, st);
			if (st == "end")break;
			str += st + "\n";
		}
		system("cls");
		cout << "造数据助手 -AC代码填写OUT\n";
		cout << "正在编译AC代码(C:\\)";
		ofstream fout("ACcode.cpp");
		fout << str;
		fout.close();
		system("g++.exe ACcode.cpp -o ACcode.exe");
		cout << "正在给予数据\n";
		int i = 1;
		while (1) {
			cout << "数据组:" << i << endl;
			char IN[] = {i / 10 + '0', i % 10 + '0', '.', 'i', 'n'};
			char sy[] = "ACcode.exe >xx.out <xx.in";
			ifstream fin(IN);
			sy[12] = i / 10 + '0';
			sy[13] = i % 10 + '0';
			sy[20] = i / 10 + '0';
			sy[21] = i % 10 + '0';
			if (!fin)break;
			system(sy);
			i++;
		}
		cout << "销毁\n";
		system("del ACcode.cpp");
		system("del ACcode.exe");
		cout << "完毕\n";
		system("pause");
	}
	if (getch() == '3') {
		system("cls");
		cout << "造数据助手 -造数据代码填写IN\n";
		cout << "->请确保造数据代码有种子语句\n";
		cout << "->请确保造数据代码没有文件语句\n";
		cout << "请键入数据组数:";
		cin >> n;
		cout << "请键入造数据代码(最后键入一行“end”结尾)\n";
		string st, str;
		while (1) {
			getline(cin, st);
			if (st == "end")break;
			str += st + "\n";
		}
		system("cls");
		cout << "造数据助手 -造数据代码填写IN\n";
		cout << "正在编译造数据代码(C:\\)";
		ofstream fout("GEcode.cpp");
		fout << str;
		fout.close();
		system("g++.exe GEcode.cpp -o GEcode.exe");

		cout << "正在给予数据\n";
		int i = 1;
		while (i <= n) {
			cout << "数据组:" << i << endl;
			char sy[] = "GEcode.exe >xx.in <seed";
			ofstream fout("seed");
			fout << rand() % 100000 + 1 << endl << i;
			fout.close();
			sy[12] = i / 10 + '0';
			sy[13] = i % 10 + '0';
			system(sy);
			i++;
		}
		cout << "销毁\n";
		system("del GEcode.cpp");
		system("del seed");
		system("del GEcode.exe");
		cout << "完毕\n";
		system("pause");
	}
	main();
}

