/*
- ����������� ����� ������� �����������.
- ����� ������ ������������� ����������� ����������� �����-������� �������.
- � ����������� �������� ������� ����������� ����� ������������� ����� ���� ������� �����-�������.
- ����� ������ ��������� ����������� ��������� ������ (������������, ���������� � ��.).
- ����� ������ ������������� ��������� ��������:
+1) �������� � ������� ����� � ��� �������,
+2) �������� ������� ���������� �����,
+3) ������ ������� ���������� �����,
+4) ��������� ������� ����� � �������,
+5) ������ ����� ���� � �������,
+6) ��������� ������� � ����, //���� ������ ������ � ����� ����� � ������, ������������ ������ ��� �����
+7) ������� ������� �� �����.
*/
#include <iostream>
#include <clocale> 
#include <string>
#include <windows.h>
#include <fstream> //��� ������ � �������
#include <sstream> //��� ������ � �������
#include <cctype> //��� �������������� � ��������
#include <cstring>
#include <locale>

using namespace std;
const int SIZE_DIC = 100; //������ �������
string Tolower(string str);

class Dictionary
{
private:
    string rus[SIZE_DIC];
    string eng[SIZE_DIC];
    int countDic; //���-�� ���� � �������
public:
    Dictionary()
    {
        rus[0];
        eng[0];
        countDic = 0;
    }
    Dictionary(string file)
    {
        ifstream in(file);
        int i = 0;
        countDic = 0;
        string line; // ���� ������ ������ �� ����� 
        string rus_l, eng_l;
        if (!in) 
        {
            cout << "���� �� ��������. ������� �� ��������� � �������� � ����� � ���������� ��������� �������� � ������ Dictionary." << endl;
        }
        while (getline(in, line))
        {
            istringstream ist(line);
            ist >> eng_l;
            ist >> rus_l;
            eng[i] = eng_l;
            rus[i] = rus_l;
            i++;
        }
        countDic = i - 1;
    }
    Dictionary(string eng_word, string rus_word)
    {
        eng[0] = eng_word;
        rus[0] = rus_word;
        countDic = 1;
    }
    Dictionary& operator=(const Dictionary& str) //�������� ������������
    {
        if (this == &str)
        {
            return *this;
        }
        for (int i = 0; i < countDic; i++)
        {
            eng[i] = str.eng[i];
            rus[i] = str.rus[i];
        }
        return *this;
    }
    void AddWord(string word, string translation) //�������� �����
    {
        int INDEX = countDic + 1;
        eng[INDEX] = word;
        rus[INDEX] = translation;
        countDic++; //����������� ���-�� ���� � �������
    }
    void changeTranslation(string word, string translation) //�������� �������
    {
        for (int i = 0; i <= countDic; i++)
        {
            if (word == eng[i])
            {
                rus[i] = translation;
                break;
            }
        }
    }
    string getTranslation(string word) //������ �������
    {
        string str;
        for (int i = 0; i <= countDic; i++)
        {
            if (eng[i] == word)
            {
                int j = i;
                str = rus[i];
                return str;
            }
        }
    }

    bool presence(string word) //����������� ����� � �������
    {
        for (int i = 0; i <= countDic; i++)
        {
            if (eng[i] == word)
            {
                return true;
                break;
            }
        }
        return false;
    }
    int sizeDictionary()
    {
        return countDic;
    }
    void saveDictoinary() //���������
    {
        ofstream file;
        file.open("Dictionary.txt");
        for (int i = 0; i <= countDic; i++)
        {
            file << eng[i];
            file << " ";
            file << rus[i];
            if (i < countDic) 
            { 
                file << endl; 
            }
        }
        file.close();
    }
    void readDictionary(string file) //�������
    {
        ifstream in(file);
        if (in.is_open())
        {
            string line; // ���� ������ ������ �� ����� 
            while (getline(in, line))
            {
                cout << line << endl; 
            }
        }
        in.close();
    }
    ~Dictionary()
    {
    }
};
string Tolower(string str) //������� �������� � �������� 
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int size_arr = 0;
    int choice_operation; //����� ��������
    string word = "";
    string translation;
    SetConsoleCP(1251); //���������� ������ �������� �����
    SetConsoleOutputCP(1251); //���������� ����� �� ������� ������� ����
    Dictionary objDictionary("Dictionary.txt");
    cout << "����� ���������� � �����-������� ������� �����������! " << endl;
    cout << "��� ��������, ������������� ���� ��� ��������, �� ����� ��������� � �����," <<endl << "���� �� ��������� ������ �� ��������� ����� 6." << endl;
    while (1)
    {
        cout << " \n������ ��������:\n1) �������� � ������� ����� � ��� �������, \n2) �������� ������� ���������� �����,\n3) ������ ������� ���������� �����,\n4) ��������� ������� ����� � �������,\n5) ������ ����� ���� � �������,\n6) ��������� ������� � ����,\n7) ������� ������� �� �����.\n8) �����\n  " << endl;
        cout << "������� ����� ������� ��� ������ ����:  ";
        cin >> choice_operation;
        while (choice_operation < 1 || choice_operation>8)
        {
            cout << " �������� � ����� ������� ���. ����������, ������ ������ ����� ��� ���: ";
            cin >> choice_operation;
        }
        switch (choice_operation)
        {
        case 1:
        {
            cout << " \n������� �����(�� ���������� �����), ������� �������� �� ������ �������� � �������: ";
            cin >> word;
            word = Tolower(word);
            cout << " \n������� �������: ";
            cin >> translation;
            translation = Tolower(translation);
            objDictionary.AddWord(word, translation);
            break;
        }
        case 2:
        {
            cout << " \n������� �����, ������� �������� �� ������ ��������: ";
            cin >> word;
            word = Tolower(word);
            while (objDictionary.presence(word) != true)// �������� �� ������������� ����� ����� � ������� 
            {
                cout << "������ ����� � ������� ���. ����������, ������� ������ ����� ��� ���: ";
                cin >> word;
                word = Tolower(word);
            }
            cout << " \n������� ����� �������: ";
            cin >> translation;
            translation = Tolower(translation);
            objDictionary.changeTranslation(word, translation);
            break;
        }
        case 3:
        {
            cout << " \n������� �����, ������� �������� �� ������ ������: ";
            cin >> word;
            word = Tolower(word);
            while (objDictionary.presence(word) == false)// �������� �� ������������� ����� ����� � ������� 
            {
                cout << "������ ����� � ������� ���. ����������, ������� ������ ����� ��� ���: ";
                cin >> word;
                word = Tolower(word);
            }
            cout << "\n�������: " << objDictionary.getTranslation(word) << endl;
            break;
        }
        case 4:
        {
            cout << " \n������� �����, ������� ������� �� ������ ���������: ";
            cin >> word;
            word = Tolower(word);
            if (objDictionary.presence(word) == false) {// �������� �� ������������� ����� ����� � ������� 
                cout << "������ ����� � ������� ���." << endl;
            }
            if (objDictionary.presence(word) == true) {
                cout << "����� ����� ���� � �������." << endl;
            }
            break;
        }
        case 5:
        {
            cout << " \n����� ���� � �������: " << objDictionary.sizeDictionary() + 1 << endl;
            break;
        }
        case 6:
        {
            cout << " \n��������� ������� � ����." << endl;
            objDictionary.saveDictoinary();
            break;
        }
        case 7:
        {
            cout << " \n���������� ���������� ������� �� �����." << endl;
            objDictionary.readDictionary("Dictionary.txt");
            break;
        }
        case 8:
        {
            return 0;
        }
        }
    }
}