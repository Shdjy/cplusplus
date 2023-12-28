// SplitString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string pattern)
{
	string::size_type pos;
	vector<string> result;
	str += pattern;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}


void Tokenize(const string& str, vector<string>& tokens, const string& delimiters)
{
	string::size_type lastpos = str.find_first_not_of(delimiters);

	string::size_type pos = str.find_first_of(delimiters, lastpos);
	while (string::npos != pos || string::npos != lastpos)
	{
		tokens.push_back(str.substr(lastpos, pos - lastpos));
		lastpos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastpos);
	}

}
int main()
{
	//使用strtok分割字符串,strtok线程不安全，可以使用strtok_s,strtok_r代替
	// 
	//char str[] = "Sun hao dong,sunhd*shd";
	//const char* d = " ,*";
	//char* p;
	//p = strtok(str, d);
	//vector<string> ss;

	//while (p)
	//{
	//	//cout << p << endl;
	//	ss.push_back(p);
	//	p = strtok(NULL, d);
	//}

	//for (int i = 0; i < ss.size(); i++)
	//{
	//	cout << ss[i] << endl;;
	//}

	/*输出结果
	Sun
	hao
	dong
	sunhd
	shd*/

	//使用strtok_s分割字符串

	
	/*char str1[] = "how are,you ";
	const char* d = " ,";
	char* head;
	char* tail;
	head = strtok_s(str1, d, &tail);
	while (head)
	{
		cout << head << endl;
		head = strtok_s(tail, d, &tail);
	}*/

	/*输出结果
	how
	are
	you*/

	//使用string的substr分割字符串
	/*size_t find (const string& str, size_t pos = 0) const; // 在当前字符串中从pos位置开始查找str字符串，返回第一次出现的位置，如果没有找到则返回string::npos1
size_t find (const char* s, size_t pos = 0) const; // 在当前字符串中从pos位置开始查找s字符串，返回第一次出现的位置，如果没有找到则返回string::npos1
size_t find (const char* s, size_t pos, size_t n) const; // 在当前字符串中从pos位置开始查找s字符串的前n个字符，返回第一次出现的位置，如果没有找到则返回string::npos1
size_t find (char c, size_t pos = 0) const; // 在当前字符串中从pos位置开始查找字符c，返回第一次出现的位置，如果没有找到则返回string::npos1
string类的substr函数可以用来从一个字符串中截取一个子字符串。它的原型有两种形式1：
string substr (size_t pos = 0, size_t len = npos) const; // 从当前字符串中的pos位置开始，截取len个字符，返回一个新的字符串，如果没有指定len或len超出了当前字符串的长度，则截取到当前字符串的结尾1
string substr (size_t pos, size_t len, size_t n) const; // 从当前字符串中的pos位置开始，截取len个字符，返回一个新的字符串，如果len超出了当前字符串的长度，则截取到当前字符串的结尾，然后在新字符串的末尾追加n个空格*/

	/*string str;
	cout << "please input str:" << endl;
	getline(cin, str);

	string pattern;
	cout << "please input pattern:" << endl;
	getline(cin, pattern);

	vector<string> result = split(str, pattern);
	cout << "The result:" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}*/

	//使用find_first_not_of分割字符串
	string str = "=====aaa======bbb===c=ddd===";
	vector<string> tokens;
	Tokenize(str, tokens, "=");
	for (int i = 0; i < tokens.size(); i++)
	{
		cout << tokens[i] << endl;
	}

	return 0;
}

