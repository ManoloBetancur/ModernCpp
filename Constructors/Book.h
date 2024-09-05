#include<iostream>

typedef std::string String;

class Book
{
    std::string title;
    std::string author;
    int year;
    int id;
    int *data;

    //Tracks the id that are already created
    static int currentID;
public:

    static int generateID()
    {
        return currentID++;
    }
    //!Default constructor
    Book(): id(generateID()) 
    {
        data = new int(10);
        std::cout << "Default Constructor call from: "<< this->id << std::endl;
    }
    //!Parameterized Constructor
    Book(const String title, const String author, int year): title(title), author(author), year(year), id(generateID()) 
    {
        data = new int(10);
        std::cout<<"Parameterized Constructor call from "<<this->id << std::endl;
    };

    //!Copy constructor
    Book(const Book &book): title(book.title), author(book.author), year(book.year), id(generateID())
    {
        // data = book.data;
        data = new int(*book.data);
        std::cout<<"Copy constructor invoked from "<<this->id << std::endl;

    }
    //!Copy assigment operator
    //Book &operator=(const Book &other) = default; SAME AS :
    Book& operator=(const Book& other) {
        std::cout << "Copy assigment operator from "<<this->id << std::endl;
        // Check for self-assignment
        if (this == &other) return *this;
        
        title = other.title;
        author = other.author;
        year = other.year;
        id = id;
        data = new int(*other.data);
        // data = other.data;

        return *this;
    }

    //!Move Constructor
    Book(Book&& other) noexcept
        : title(other.title), author(other.author), year(other.year), id(generateID()), data(other.data) {
        // Nullify the source object’s pointers to avoid double deletion
        other.data = nullptr;
        std::cout << "Move constructor call of " << this->id << std::endl;
    }

    //!Move assigment operator
    Book &operator=(Book &&other) noexcept
    {
        if(this != &other)
        {
            delete data;
            title = other.title; 
            year = other.year;
            author = other.author; 
            id = generateID();
            data = other.data;
            std::cout << "Move assigment operator call of " << this->id << std::endl;
            other.data = nullptr;
        }
        return *this;
    }


    ~Book()
    {
        delete data;
        std::cout << "Destroying obj (" << this->id << ")"<<std::endl;
        this->currentID--;
    }


    int getData()
    {
        return *data;
    }
    int *getDataptr()
    {
        return data;
    }
    void setValue(int value)
    {
        if(data==nullptr) data = new int;
        *data = value;
    }
    void seeBookData()
    {
        std::cout << "Title: \"" << title 
            << "\", Author: " << author 
            << ", Year: " << year 
            << ", ID: " << id 
            << ", Inner Value: "<<getData()<< std::endl;
    }


};

