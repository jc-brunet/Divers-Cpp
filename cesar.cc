#include <iostream>
using namespace std;

char code(char, int);
string code(string, int);
string decode(string, int);

char decale(char, char, long);

int main()
{
	string test = "Fuyez manants";
	cout << code(test, 4) << endl;
	cout << code(test, 6) << endl;
	cout << code(test, -4) << endl;
	string testDeux = "Avez-vous vu mes 3 chats et mes 2 chiens ?";
	cout << code(testDeux, 4) << endl;

	string testTrois = "Jycid qererxw";
	string testQuatre = "Laekf sgtgtzy";
	string testCinq = "Bquav iwjwjpo";
	string testSix = "Ezid-zsyw zy qiw 3 glexw ix qiw 2 glmirw? ";

	cout << decode(testTrois, 4) << endl;
	cout << decode(testQuatre, 6) << endl;
	cout << decode(testCinq, -4) << endl;
	cout << decode(testSix, 4) << endl;

	return 0;
}

char decale(char c, char debut, long decalage)
{
	while (decalage < 0)
	{
		decalage += 26;
	}
	return (debut + (((c - debut) + decalage) % 26));
};

char code(char c, int d)
{
	if (c >= 'a' && c <= 'z')
	{
		return decale(c, 'a', d);
	}

	if (c >= 'A' && c <= 'Z')
	{
		return decale(c, 'A', d);
	}

	return c;
};

string code(string stringACoder, int decalage)
{
	string stringCodee = "";
	for (auto character : stringACoder)
	{
		stringCodee.push_back(code(character, decalage));
	}
	return stringCodee;
}

string decode(string aDecoder, int decalage)
{
	return code(aDecoder, -decalage);
}