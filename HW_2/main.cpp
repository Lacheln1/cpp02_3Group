#include "UI.h"
#include "GraphicEditor.h"
#include <iostream>
using namespace std;

int main() {
    GraphicEditor* g[100];
    UI::start();
    int index = 0;

    for (;;) {
        int m = UI::menu();
        if (m == 1) {
            int n = UI::insert();
            if (n == 1) {
                Line* l = new Line(index);
                g[index] = l;
                ++index;
            }
            else if (n == 2) {
                Circle* c = new Circle(index);
                g[index] = c;
                ++index;
            }
            else if (n == 3) {
                Rect* r = new Rect(index);
                g[index] = r;
                ++index;
            }
            else std::cout << "입력 에러" << std::endl;
        }
        else if (m == 2) {
            int n = UI::del();
            for (int i = n; i < index - 1; ++i) {
                g[i] = g[i + 1];
                g[i]->subnum();
            }
            --index;
        }
        else if (m == 3) {
            for (int i = 0; i < index; ++i)
                g[i]->show();
        }
        else if (m == 4)
            break;
        else
            std::cout << "입력 에러 " << std::endl;
    }

    // 동적 할당된 객체 삭제
    for (int i = 0; i < index; ++i)
        delete g[i];

    return 0;
}