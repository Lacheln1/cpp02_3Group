#include "UI.h"
#include "GraphicEditor.h"
#include <iostream>

int UI::num = 0;

void UI::start() {
    std::cout << "�׷��� �������Դϴ�." << std::endl;
}

int UI::menu() {
    std::cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
    std::cin >> num;
    return num;
}

int UI::insert() {
    std::cout << "��:1, ��:2, �簢��:3 >> ";
    std::cin >> num;
    return num;
}

int UI::del() {
    std::cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
    std::cin >> num;
    return num;
}