#include <array>
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

class Dish {
private:
    string description;

public:
    Dish(string description) {
        this->description = description;
    }

    string get_description() {
        return this->description;
    }
};

class DishStack {
  private:
    int top;
    Dish stack[MAX_SIZE];
    bool isFull() const {
        return top == MAX_SIZE;
    }
  public:
    explicit DishStack(int stack_size)
        : top(stack_size), stack{{""},{""},{""},{""},{""},{""},{""},{""},{""}, {""}} {
    }

    void push(const Dish dish) {
        if (!isFull()) {
            this->top++;
            stack[top-1] = dish;
        }else {
            cout << "Stack is full" << endl;
        }
    }
    Dish pop() {
        if (top != 0){
            top--;
            return stack[top];
        }
        cout << "Stack is empty" << endl;
        return {"Error"};
    }
    Dish peek() const {
        if (top != 0) {
            return stack[top-1];
        }
        return {"Error"};
    }
    int size() const {
        return top;
    }
};

int main() {
    DishStack stack(0);
    Dish one_dish = Dish("A dish with one fish pattern on it");
    Dish two_dish = Dish("A dish with two fish patterns on it");
    Dish red_dish = Dish("A dish with a red fish pattern on it");
    Dish blue_dish = Dish("A dish with a blue fish pattern on it");

    // The variable stack_size should equal zero.
    int stack_size = stack.size();
    cout << "Stack size: " << stack_size << endl;

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    // The variable size_after_pushes should equal four.
    int size_after_pushes = stack.size();
    cout << "after pushes: " << size_after_pushes << endl;

    // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
    Dish peeked_dish = stack.peek();
    cout << "Desc 1: " << peeked_dish.get_description() << endl;

    // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
    Dish popped_dish = stack.pop();
    cout << "Desc 2: " << popped_dish.get_description() << endl;

    // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
    Dish another_popped_dish = stack.pop();
    cout << "another popped: " << another_popped_dish.get_description() << endl;

    // The variable final_size should equal two.
    int final_size = stack.size();
    cout << "final: " << final_size << endl;
}