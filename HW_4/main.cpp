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
        cout << "-----��ǰ Ŀ�� ���Ǳ⸦ �����մϴ�.-----" << endl;
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
                cout << "���α׷��� �����մϴ�..." << endl;
                exit(0);
            }

            if (!ingredients[0]->consumeAmount(1)) {
                cout << "��ᰡ �����մϴ�." << endl;
                showCoffeeMachineState();
                continue;
            }
            if (!ingredients[3]->consumeAmount(1)) {
                cout << "��ᰡ �����մϴ�." << endl;
                showCoffeeMachineState();
                continue;
            }
            if (!ingredients[4]->consumeAmount(1)) {
                cout << "��ᰡ �����մϴ�." << endl;
                showCoffeeMachineState();
                continue;
            }

            switch (choice) {
            case 0:
                if (!ingredients[2]->consumeAmount(1)) {
                    cout << "��ᰡ �����մϴ�." << endl;
                    showCoffeeMachineState();
                    continue;
                }
                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;
            case 1:
                if (!ingredients[1]->consumeAmount(1)) {
                    cout << "��ᰡ �����մϴ�." << endl;
                    showCoffeeMachineState();
                    continue;
                }
                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;
            case 2:
                cout << "���ִ� �� Ŀ�� ���Խ��ϴ�~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;
            default:
                cout << "�߸��� �Է��Դϴ�." << endl << endl;
                break;
            }
        }
    }

    void showMenu() {
        cout << "���� Ŀ��: 0, ���� Ŀ��: 1, �� Ŀ��: 2, ä���: 3, ����: 4 >> ";
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
        cout << "��� ��Ḧ ä��ϴ�~~" << endl;
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