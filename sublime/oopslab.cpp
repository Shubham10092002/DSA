/*#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    int id;
    string author;
    string title;
    double price;
    string publisher;
    int stockPosition;

public:
    // Constructors
    Book() {
        id = 0;
        author = "";
        title = "";
        price = 0.0;
        publisher = "";
        stockPosition = 0;
    }

    Book(int bookId, const string& bookAuthor, const string& bookTitle, double bookPrice, const string& bookPublisher, int bookStockPosition) {
        id = bookId;
        author = bookAuthor;
        title = bookTitle;
        price = bookPrice;
        publisher = bookPublisher;
        stockPosition = bookStockPosition;
    }

    // Member functions
    void displayDetails() {
        cout << "ID: " << id << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock Position: " << stockPosition << endl;
    }

    int getId() const {
        return id;
    }

    bool isAvailable() const {
        return (stockPosition > 0);
    }
};

int main() {
    // Create an array of books
    const int numBooks = 3;
    Book books[numBooks];

    // Initialize book details
    books[0] = Book(1, "John Doe", "Book 1", 10.99, "Publisher A", 5);
    books[1] = Book(2, "Jane Smith", "Book 2", 12.99, "Publisher B", 0);
    books[2] = Book(3, "David Johnson", "Book 3", 8.99, "Publisher C", 2);

    // Get book ID from the user
    int bookId;
    cout << "Enter book ID: ";
    cin >> bookId;

    // Search for the book and display details
    bool bookFound = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].getId() == bookId) {
            bookFound = true;
            cout << "Book Found!" << endl;
            books[i].displayDetails();
            break;
        }
    }

    if (!bookFound) {
        cout << "Book not found." << endl;
    }

    return 0;
}*/




#include <iostream>

class Vector {
private:
    int data[3];

public:
    Vector() {
        for (int i = 0; i < 3; i++) {
            data[i] = 0;
        }
    }

    void readVector() {
        std::cout << "Enter vector elements (Ai, Bj, Ck): ";
        for (int i = 0; i < 3; i++) {
            std::cin >> data[i];
        }
    }

    void multiply(const Vector& other) {
        for (int i = 0; i < 3; i++) {
            data[i] *= other.data[i];
        }
    }

    void displayVector() {
        std::cout << "Resultant vector: ";
        for (int i = 0; i < 3; i++) {
            std::cout << data[i] << "i";
            if (i < 2) {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector* vector1 = new Vector();
    Vector* vector2 = new Vector();

    vector1->readVector();
    vector2->readVector();

    vector1->multiply(*vector2);
    vector1->displayVector();

    delete vector1;
    delete vector2;

    return 0;
}/*#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;  // Integer matrix data member

public:
    Matrix(const std::vector<std::vector<int>>& matrix) : data(matrix) {}

    // Overloading ~ operator to find the transpose of the matrix
    Matrix operator~() {
        std::vector<std::vector<int>> transposed(data[0].size(), std::vector<int>(data.size()));

        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                transposed[j][i] = data[i][j];
            }
        }

        return Matrix(transposed);
    }

    // Utility function to display the matrix
    void displayMatrix() {
        for (const auto& row : data) {
            for (int element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrixData = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix matrix(matrixData);

    std::cout << "Original Matrix:" << std::endl;
    matrix.displayMatrix();

    Matrix transposedMatrix = ~matrix;

    std::cout << "\nTransposed Matrix:" << std::endl;
    transposedMatrix.displayMatrix();

    return 0;
}
*/

    #include <iostream>
#include <string>

using namespace std;

class Textbook {
private:
    string title;
    float price;
    char bookClass;
    string subjectName;
    int pages;

public:
    // Default constructor
    Textbook() {}

    // Parameterized constructor
    Textbook(const string& _title, float _price, char _bookClass, const string& _subjectName, int _pages)
        : title(_title), price(_price), bookClass(_bookClass), subjectName(_subjectName), pages(_pages) {}

    // Member function to read data
    void readData() {
        cout << "Enter the Title: ";
        getline(cin, title);
        cout << "Enter the Price: ";
        cin >> price;
        cin.ignore(); // Ignore the newline character left in the input stream
        cout << "Enter the Class (I-V): ";
        cin >> bookClass;
        cin.ignore(); // Ignore the newline character left in the input stream
        cout << "Enter the Subject Name: ";
        getline(cin, subjectName);
        cout << "Enter the Number of Pages: ";
        cin >> pages;
    }

    // Member function to display data
    void displayData() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
        cout << "Class: " << bookClass << endl;
        cout << "Subject Name: " << subjectName << endl;
        cout << "Number of Pages: " << pages << endl;
    }
};

int main() {
    // Create a pointer to a Textbook object
    Textbook* bookPtr;

    // Dynamically allocate memory for a Textbook object
    bookPtr = new Textbook;

    // Read data using member function through the pointer
    bookPtr->readData();

    cout << "\nEntered Data:\n";
    // Display data using member function through the pointer
    bookPtr->displayData();

    // Deallocate memory
    delete bookPtr;

    return 0;
}
/*#include <iostream>
#include <climits>

class Array {
private:
    int *arr;
    int size;

public:
    Array(int size) {
        this->size = size;
        arr = new int[size];
    }

    ~Array() {
        delete[] arr;
    }

    void readArray() {
        std::cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

    void display() {
        std::cout << "Array: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int largest() {
        int max = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    int smallest() {
        int min = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    Array array(size);
    array.readArray();

    array.display();
    std::cout << "Largest element: " << array.largest() << std::endl;
    std::cout << "Smallest element: " << array.smallest() << std::endl;

    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

class point{
public:
    int x,y;

    void getdata(){
        cin >> x >> y;

    }
    friend void distance(point ,point );

    

};

void distance(point a,point b){

    int Distance=sqrt((a.x-b.x)*(a.x-b.x) - (a.y-b.y)*(a.y-b.y));

    cout << "Distance between two point is: "<< Distance << endl;
}

int main(){

    point c, d;
    c.getdata();
    d.getdata();

    distance(c,d);
    return 0;
}



