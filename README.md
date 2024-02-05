# Library management system
# 1. Introduction
1.1 The system provides basic functionalities for managing a library, including adding books, displaying the catalog, searching for books based on various criteria, and deleting books. The system employs a simple console-based user interface.

# 2. Features
1. Add Book
2.1.1 Users can add one or more books to the library catalog.
2.1.2 The system ensures that the maximum number of books (MAX_BOOKS) is not exceeded.
2.1.3 Unique IDs are assigned to each book automatically.

2. Display Books
2.2.1 Users can view the entire library catalog with details such as ID, title, and author name.

3. Search Books
2.3.1 Search options include: Searching books by the first letter of the title and Searching books by the author's first name.

4. Delete Books
2.4.1 Users can delete a book from the catalog by specifying its ID.
2.4.2 The system renumbers the remaining book IDs after deletion.

5. User interface
2.5.1 Users interact with the system through a simple console-based menu.
2.5.2 The main menu offers options to add, display, search, delete books, and exit the system.

# 3. Code Structure
1. Global variables
3.1.1 MAX_BOOKS: Maximum number of books the system can handle.
3.1.2 book_count: Tracks the current number of books in the catalog.

2. Book Structure
3.2.1 struct book: Holds information about a book, including title, author name, and ID.

3. Functions
3.3.1 add_book: Adds one or more books to the library catalog.
3.3.2 display_books: Displays the entire library catalog.
3.3.3 search_by_first_letter: Searches and displays books based on the first letter of the title
3.3.4 search_by_author_first_name: Searches and displays books by the author's first name.
3.3.5 delete_book: Deletes a book from the catalog by specifying its ID.
3.3.6 main: The main function implementing the user interface and integrating the above functions.

# 4. Execution
4.1.1 Compile and run the program using a C compiler.
4.1.2 Follow the on-screen menu to perform various operations.
4.1.3 The system loops until the user chooses the exit option.

# 5. How to use
1. Adding Books
5.1.1 Choose option 1 from the main menu.
5.1.2 Enter the number of books to add.   
5.1.3 Input title and author information for each book.

2. Displaying Books
5.2.1 Choose option 2 from the main menu.
5.2.2 The entire library catalog with book details will be displayed.

3. Searching Books
5.3.1 Choose option 3 from the main menu.
5.3.2 Select the search criteria (first letter or author).
5.3.3 Follow the on-screen instructions to input search parameters.

4. Deleting Books
5.4.1 Choose option 4 from the main menu.
5.4.2 Input the ID of the book to be deleted.

5. Exiting
5.5.1 Choose option 5 from the main menu to exit the system.

# 6. Error Handling
6.1.1 The system handles errors such as exceeding the maximum number of books, invalid choices, and book not found during deletion.

# 7. Conclusion
This Library Management System provides a basic yet functional solution for managing a library catalog. Users can easily perform common library operations such as adding, displaying, searching, and deleting books through a simple console interface. The code is structured for readability and includes error handling for a smoother user experience.
