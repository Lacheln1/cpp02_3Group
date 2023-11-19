#include "UI.h"
#include "GraphicEditor.h"
#include <iostream>

int UI::num = 0;

void UI::start() {
    std::cout << "그래픽 에디터입니다." << std::endl;
}

int UI::menu() {
    std::cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
    std::cin >> num;
    return num;
}

int UI::insert() {
    std::cout << "선:1, 원:2, 사각형:3 >> ";
    std::cin >> num;
    return num;
}

int UI::del() {
    std::cout << "삭제하고자 하는 도형의 인덱스 >> ";
    std::cin >> num;
    return num;
}