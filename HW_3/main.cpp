#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include <vector>
using namespace std;
class monitor { 
    static int n; 
public:
    static void msg();
    static int menu(); 
    static int insert(); 
    static int del(); 
};
int monitor::n = 0;
void monitor::msg() {
    cout << "그래픽 에디터입니다." << endl;
}
int monitor::menu() {
    cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
    cin >> n;
    return n;
}
int monitor::insert() {
    cout << "선:1, 원:2, 사각형:3 >> ";
    cin >> n;
    return n;
}
int monitor::del() { 
    cout << "삭제하고자 하는 도형의 인덱스 >> ";
    cin >> n;
    return n;
}
class Editor {
    vector<Shape*> v;
    vector<Shape*>::iterator it;
public:
    Editor() {}
    void insert() {
        int n = monitor::insert();
        if (n == 1) 
            v.push_back(new Line());
        else if (n == 2)  
            v.push_back(new Circle());
        else if (n == 3) 
            v.push_back(new Rect());
        else cout << "입력 에러" << endl;
    }
    void deleteShape() {
        int n = monitor::del();
        Shape* del;
        it = v.begin();
        for (int i = 0; i < n; ++i)
            ++it;
        del = *it;
        it = v.erase(it);
        delete del;
    }
    void showAll() {
        for (int i = 0; i < v.size(); ++i) {
            cout << i << ": ";
            v[i]->paint();
        }
    }
    void start() {
        monitor::msg();
        for (;;) {
            int m = monitor::menu();
            if (m == 1)
                insert();
            else if (m == 2) 
                deleteShape();
            else if (m == 3)  
                showAll();
            else if (m == 4) break;
            else cout << "에러 " << endl;
        }
    }
};
int main() {
    Editor* g = new Editor;
    g->start();
    delete g;
}