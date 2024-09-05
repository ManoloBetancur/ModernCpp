#include<iostream>
#include"Book.h"
#include<memory>


int Book::currentID = 1000;

void getObj(std::shared_ptr<Book> obj)
{
    obj->setValue(255);
    obj->seeBookData();
    std::cout << "Exiting function that takes ownership, after this the function must destroy this obj."<< std::endl;
}

Book creatingSaga()
{
    Book tempBook = {"Harry potter CS", "J.K Rowling", 1998};

    //! This invokes the move constructor.
    return tempBook;
}

int main() {
    //Direct initialization, 
    Book *bk2= new Book{"El coronel no tiene quien lo escriba", "Gabriel Garcia Marquez", 1961};//Parameterized constructor call.
    // auto bk2 = std::make_shared<Book>("El coronel no tiene quien lo escriba", "Gabriel Garcia Marquez", 1961);//Parameterized constructor call

    Book *bk3 = new Book(*bk2); //Copy constructor call

    bk3->seeBookData();
    bk2->setValue(26);
    bk2->seeBookData();
    //!For a default copy constructor, Even though the value is change in bk2, the value of the bk3 is also change.
    //!Problem fixed by implementing a custom copy consctrot where new memory allocates new memory to its value.
    // bk3->seeBookData(); 
    delete bk2;
    //!If a default copy constructor was used, the value of the pointer would be corrupted.
    bk3->seeBookData();
    delete bk3;

    // //!Using smart pointers 
    // Book *bk = new Book{"Hamlet", "William Shakespeare", 1600}; //List Initialization, Parameterized constructor call
    std::shared_ptr<Book> book1 = std::make_shared<Book>("Hamlet", "William Shakespeare", 1600); //Parameterized constructor call

    std::shared_ptr<Book> book2 = std::make_shared<Book>(*book1); //Copy constructor call

    book2->seeBookData();
    book1->setValue(48);
    book1->seeBookData();
    book1.reset(); //Deleting memory allocation
    book2->seeBookData();
    getObj(std::move(book2)); //Passing onwership
    if(book2==nullptr)
    {
        std::cout << "This obj is empty, due to the std::move()"<<std::endl;
    }
    book2.reset();

    //?If a obj was already create beforehand, you must set a copy assigment operator assign a copy of an obj to the new obj.
    std::shared_ptr<Book> book = std::make_shared<Book>(); //SAME AS Book *book = new Book(); this invokes Default constructor
    std::shared_ptr<Book> book3 = std::make_shared<Book>("1984", "George Orwell", 1949);
    //!Creating a copy of book1 into book
    //!Invoking copy assigment operator function
    *book = *book3; //Shallow copy if only set it as default.
    book->seeBookData();
    book->setValue(87);
    book->seeBookData();
    book.reset();//Releasing resources
    book3->seeBookData();
    book3.reset();//Releasing resources

    //?IF you want to move the content of and obj to another obj efficently without creating a temporary copy you use the "Move Constructor"
    //The obj that moved their resources to another obj using move semantincs, remains in a valid but unspecified state because their pointer was set to nullptr
    //However, the obj is not completly empty and capable of being re assign
    std::shared_ptr B = std::make_shared<Book>("Harry potter CS", "J.K Rowling", 1998);
    B->seeBookData();
    auto B2 = std::make_shared<Book>(std::move(*B));//!Invokes the move Consctructor
    //!Same data of B, but B resourses are released
    B2->seeBookData();

    //?This is not longer valid. Data can be seen for some primitive members functions but corrupted and pottential crash the program when dereference the data pointer
    // B->seeBookData();

    //! IF move constructor has a default behavior the pointers and dynamic allocated members variables are moved and not longer valid
    //! In this case the Inner value does not have a valid value an B obj does not have the ownership of the data resources.
    if(B->getDataptr() == nullptr) std::cout << "Data pointer of B is nullptr"<<std::endl;
    //?If B is re assign with new valid values, it would be a full functional obj again.
    B->setValue(98);
    //Now this is valid again
    B->seeBookData();

    B.reset();//Releasing resources
    B2.reset();//Releasing Resources

    //!Extra example with unique_ptr
    std::unique_ptr<Book> book_1 = std::make_unique<Book>("The Great Gatsby","F. Scoot Fitzgerald",1925); //Parameterized constructor

    book_1->seeBookData();

    std::unique_ptr<Book> book_2 = std::make_unique<Book>();

    book_2 = std::move(book_1);
    book_2->seeBookData();
    if(book1==nullptr) std::cout<<"NULLPTR"<<std::endl;
    book1.reset();
    book2.reset();

    //!Using regular pointers
    Book *bookA = new Book("The Great Gatsby","F. Scoot Fitzgerald",1925);
    Book *bookB = new Book();


    *bookB = std::move(*bookA);
    
    bookB->seeBookData();

    return 0;
}