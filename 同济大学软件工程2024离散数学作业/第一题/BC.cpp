#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

typedef map<char, int> Map_ci;
typedef map<int, char> Map_ic;
typedef map<int, int> Map_ii;


Map_ci priority;

Map_ic getProposition(string formula);
int findProposition(Map_ic, char p);
int pow2(int n);
Map_ii toBinary(int n_proposition, int index);
int calculate(string formula, Map_ic pSet, Map_ii value);
void check(stack<int>& value, stack<char>& opter);

int main()
{
	priority['('] = 6;
	priority[')'] = 6;
	priority['!'] = 5;
	priority['&'] = 4;
	priority['|'] = 3;
	priority['^'] = 2;
	priority['~'] = 1;
	priority['#'] = 0;


	cout << "***************************************\n";
	cout << "**                                   **\n";
	cout << "**         ��ӭ�����߼��������      **\n";
	cout << "**   (��������ֵ��,����ʽ,֧������)  **\n";
	cout << "**                                   **\n";
	cout << "**              ��!��ʾ��            **\n";
	cout << "**              ��&��ʾ��            **\n";
	cout << "**              ��|��ʾ��            **\n";
	cout << "**             ��^��ʾ�̺�           **\n";
	cout << "**             ��~��ʾ��ֵ           **\n";
	cout << "**                                   **\n";
	cout << "***************************************\n\n";
	cout << "������һ���Ϸ������⹫ʽ��" << endl;
	string formula;
	cin >> formula;
	Map_ic proposition_set = getProposition(formula);
	cout << "��ʽ���еı�������Ϊ��" << proposition_set.size() << endl << "�����ֵ�����£�" << endl;
	for (unsigned int i = 0; i < proposition_set.size(); i++)
	{
		cout << proposition_set[i] << "\t";
	}
	cout << formula << endl;
	int* m;
	m = (int*)malloc(sizeof(int) * pow2(proposition_set.size())); 

	for (int i = 0; i < pow2(proposition_set.size()); i++)
	{
		Map_ii bina_set = toBinary(proposition_set.size(), i);
		for (unsigned int j = 0; j < bina_set.size(); j++)
		{
			cout << bina_set[j] << "\t";
		}
		int result = calculate(formula, proposition_set, bina_set);

		*(m + i) = result;
		cout << result << endl;
	}
	int n_m = 0, n_M = 0;
	cout << "�����⹫ʽ������ȡ��ʽ��" << endl;
	for (int i = 0; i < pow2(proposition_set.size()); i++)
	{
		if (*(m + i) == 0)
		{
			if (n_M == 0)
			{
				cout << "M<" << i << ">";
			}
			else
			{
				cout << "\\/M<" << i << ">";
			}
			n_M++;
		}
	}
	if (n_M == 0)
	{
		cout << "0";
	}
	cout << endl;
	cout << "�����⹫ʽ������ȡ��ʽ��" << endl;
	for (int i = 0; i < pow2(proposition_set.size()); i++)
	{
		if (*(m + i) == 1)
		{
			if (n_m == 0)
			{
				cout << "m<" << i << ">";
			}
			else
			{
				cout << "/\\m<" << i << ">";
			}
			n_m++;
		}
	}
	if (n_m == 0)
	{
		cout << "0";
	}
	cout << endl;
	
	cout << endl;
	cout << "��ӭ�´��ٴ�ʹ�ã�" << endl;
	return 0;
}

int findProposition(Map_ic pSet, char p) 
{
	Map_ic::iterator it = pSet.begin();
	while (it != pSet.end())
	{
		if (it->second == p)
		{
			return it->first;
		}
		it++;
	}
	return -1;
}


Map_ic getProposition(string formula)
{
	Map_ic proposition;
	int n_proposition = 0;
	for (unsigned int i = 0; i < formula.length(); i++)
	{
		char c = formula[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			int r = findProposition(proposition, c);

			if (r == -1)
			{
				proposition[n_proposition] = c;
				n_proposition++;
			}
		}
		else if (!priority.count(c))
		{
			cout << c << " is undefined!" << endl;
			exit(2);
		}
	}
	return proposition;
}

Map_ii toBinary(int n_proposition, int index) 
{
	Map_ii result;
	for (int i = 0; i < n_proposition; i++)
	{
		int r = index % 2;
		result[n_proposition - 1 - i] = r;
		index = index / 2;
	}
	return result;
}

int pow2(int n)   
{
	if (n == 0)
		return 1;
	else
		return 2 * pow2(n - 1);
}


int calculate(string formula, Map_ic pSet, Map_ii value) 
{
	stack<char> opter;
	stack<int> pvalue;
	opter.push('#');
	formula = formula + "#";
	for (unsigned int i = 0; i < formula.length(); i++)
	{
		char c = formula[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			pvalue.push(value[findProposition(pSet, c)]);
		}
		else
		{
			char tmp = opter.top();
			if (priority[tmp] > priority[c])
			{
				while (priority[tmp] > priority[c] && tmp != '(')
				{
					check(pvalue, opter);
					tmp = opter.top();
					if (tmp == '#' && c == '#')
					{
						return pvalue.top();
					}
				}
				opter.push(c);
			}
			else
				opter.push(c);
		}
	}
	return -1;
}


void check(stack<int>& value, stack<char>& opter) 
{
	int p, q, result;
	char opt = opter.top();

	switch (opt)
	{
	case '&':
		p = value.top();
		value.pop();
		q = value.top();
		value.pop();
		result = p && q;
		value.push(result);
		opter.pop();
		break;

	case '|':
		p = value.top();
		value.pop();
		q = value.top();
		value.pop();
		result = p || q;
		value.push(result);
		opter.pop();
		break;

	case '!':
		p = value.top();
		value.pop();
		result = !p;
		value.push(result);
		opter.pop();
		break;

	case '^':
		q = value.top();
		value.pop();
		p = value.top();
		value.pop();
		result = !p || q;
		value.push(result);
		opter.pop();
		break;

	case '~':
		p = value.top();
		value.pop();
		q = value.top();
		value.pop();
		result = (!p || q) && (p || !q);
		value.push(result);
		opter.pop();
		break;

	case '#':
		break;

	case '(':
		break;

	case ')':
		opter.pop();
		while (opter.top() != '(')
		{
			check(value, opter);
		}
		if (opter.top() == '(')
		{
			opter.pop();
		}
		break;

	default:
		break;
	}
}
