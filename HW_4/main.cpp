#include <iostream>
#include <iomanip>
using namespace std;

class Ingredient {
protected:
    string name;
    int amount;
public:
    string getName() {
        return name;
    }
    int getAmount() {
        return amount;
    }
    void setAmount(int amount) {
        this->amount = amount;
    }
    bool consumeAmount(int amount) {
        if (this->amount <= 0)
            return false;
        else
            this->amount -= amount;
        return true;
    }
};

class CoffeeIngredient : public Ingredient {
public:
    CoffeeIngredient(const string& name, int initialAmount) {
        this->name = name;
        this->amount = initialAmount;
    }
};

class CoffeeMachine {
    Ingredient* ingredients[5];
public:
    CoffeeMachine() {
        cout << "-----명품 커피 자판기를 시작합니다.-----" << endl;
        ingredients[0] = new CoffeeIngredient("Coffee", 3);
        ingredients[1] = new CoffeeIngredient("Sugar", 3);
        ingredients[2] = new CoffeeIngredient("Cream", 3);
        ingredients[3] = new CoffeeIngredient("Water", 3);
        ingredients[4] = new CoffeeIngredient("Cup", 3);
        showCoffeeMachineState();
        cout << endl;
    }

    void showCoffeeMachineState() {
        for (int i = 0; i < 5; i++) {
            cout << setw(10) << ingredients[i]->getName();
            for (int j = 0; j < ingredients[i]->getAmount(); j++)
                cout << "*";
            cout << endl;
        }
    }

    void start() {
        int choice;
        while (true) {
            showMenu();
            choice = selectMenu();

            if (choice == 3) {
                refillIngredients();
                continue;
            }
            else if (choice == 4) {
                cout << "프로그램을 종료합니다..." << endl;
                exit(0);
            }

            if (!ingredients[0]->consumeAmount(1)) {
                cout << "재료가 부족합니다." << endl;
                showCoffeeMachineState();
                continue;
            }
            if (!ingredients[3]->consumeAmount(1)) {
                cout << "재료가 부족합니다." << endl;
                showCoffeeMachineState();
                continue;
            }
            if (!ingredients[4]->consumeAmount(1)) {
                cout << "재료가 부족합니다." << endl;
                showCoffeeMachineState();
                continue;
            }

            switch (choice) {
            case 0:
                if (!ingredients[2]->consumeAmount(1)) {
                    cout << "재료가 부족합니다." << endl;
                    showCoffeeMachineState();
                    continue;
                }
                cout << "맛있는 보통 커피 나왔습니다~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;
            case 1:
                if (!ingredients[1]->consumeAmount(1)) {
                    cout << "재료가 부족합니다." << endl;
                    showCoffeeMachineState();
                    continue;
                }
                cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;
            case 2:
                cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;
            default:
                cout << "잘못된 입력입니다." << endl << endl;
                break;
            }
        }
    }

    void showMenu() {
        cout << "보통 커피: 0, 설탕 커피: 1, 블랙 커피: 2, 채우기: 3, 종료: 4 >> ";
    }

    int selectMenu() {
        int choice;
        cin >> choice;
        return choice;
    }

    void refillIngredients() {
        for (int i = 0; i < 5; i++) {
            ingredients[i]->setAmount(3);
        }
        cout << "모든 재료를 채웁니다~~" << endl;
        showCoffeeMachineState();
        cout << endl;
    }
};

int main() {
    cout.setf(ios::left);
    CoffeeMachine coffeeMachine;
    coffeeMachine.start();

    return 0;
}