#include "GraphicEditor.h"
#include <iostream>

GraphicEditor::GraphicEditor(int i) : num(i) {}

int GraphicEditor::getnum() {
    return num;
}

void GraphicEditor::subnum() {
    --num;
}

Line::Line(int index) : GraphicEditor(index) {}

void Line::show() {
    std::cout << getnum() << ": Line" << std::endl;
}

Circle::Circle(int index) : GraphicEditor(index) {}

void Circle::show() {
    std::cout << getnum() << ": Circle" << std::endl;
}

Rect::Rect(int index) : GraphicEditor(index) {}

void Rect::show() {
    std::cout << getnum() << ": Rectangle" << std::endl;
}