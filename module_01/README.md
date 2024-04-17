# Object Relationships and Illustrative Example 🌐

In the realm of Object-Oriented Programming (OOP), objects engage in various relationships, facilitating interaction and data sharing. These relationships can be categorized based on the degree of dependence and ownership, resulting in different types of connections.

For instance, there's a relationship where one object is composed of others, and these contained objects are essential for the primary object's functionality. This signifies a robust bond between objects, showcasing one's reliance on the other.

Another type involves objects with a loose connection, allowing one object to function independently without direct reliance on the other, representing a scenario of loose coupling.

A third relationship type features objects with a common responsibility, yet neither is dependent on the other. This scenario reflects a collaborative effort between objects, each contributing to a shared task without direct dependency.

## Example: Computer System Relationships 💻

Let's use a computer system as an object to illustrate these relationships in a real-world context, aiding in code organization, maintenance, and extension.

- The `Central Processing Unit (CPU)` and the `Screen` exhibit a loose relationship. While the screen is a distinct object, it contributes to the computer's functionality when associated with it, enhanvcing display capabilities.

- In contrast, the `CPU` and the `Graphics Processing Unit (GPU)` share a strong relationship. The GPU is an integral part of the computer, essential for its functionality. The computer is the main object, and the GPU is a contained object crucial to its operation.

- The `Computer` and `Printer` share a relationship based on a common responsibility. Both can independently perform their tasks, but when connected, they collaborate to execute printing operations. This collaboration is marked by mutual independence.

- Lastly, the `CPU` serves as the parent class, and the `Processor` object is the child class. The processor inherits properties and behaviors from the CPU, such as clock speed and core count, while also specializing by adding specific information like make and model.

---

When exploring object relationships, the concept of message passing comes into play. Here, one object initiates the invocation of an operation on another, often characterized by unidirectional communication. However, bidirectional characteristics may emerge in certain scenarios, allowing for mutual message exchange between involved objects. This dynamic interplay of message passing forms the foundation for establishing connections and enabling collaboration within object-oriented systems.

In the context of object interactions, an object may play one of the following roles:

- **Controller**: This object can perform operations on other objects but is not subject to operations from others. In certain contexts, the terms "active object" and "controller" are interchangeable.

- **Server**: This object does not perform operations on other objects; instead, it is acted upon by other objects.

- **Proxy**: This object has the capability to both perform operations on other objects and be subject to operations from others. Proxies are commonly employed to represent real-world objects within the application's domain. 🔄

## Association relationship 🔗

**Definition:** Association represents a relationship between two or more objects, indicating that they are connected in some way. It is a more generic relationship that does not specify the strength or nature of the connection.

### Example:

Consider a scenario where a `Teacher` is associated with multiple `Students`. The association does not dictate ownership, and both teachers and students can exist independently. The relationship is characterized by the teacher having students, but students are not owned by the teacher.

### C++ Example:

```cpp
#include <iostream>
#include <vector>

class Student {
public:
    std::string name;

    Student(std::string studentName) : name(studentName) {}
};

class Teacher {
public:
    std::string name;
    std::vector<Student> students;

    Teacher(std::string teacherName) : name(teacherName) {}

    void enrollStudent(const Student& student) {
        students.push_back(student);
    }

    void displayTeacherInfo() {
        std::cout << "Teacher: " << name << std::endl;
        std::cout << "Students Enrolled:" << std::endl;
        for (const auto& student : students) {
            std::cout << "- " << student.name << std::endl;
        }
    }
};

// Association between Teacher and Student
Teacher mathTeacher("Ms. Johnson");
Student student1("Alice");
Student student2("Bob");

mathTeacher.enrollStudent(student1);
mathTeacher.enrollStudent(student2);

// Display Teacher and Student Information
mathTeacher.displayTeacherInfo();
```
<hr>
<b>Aggregation and Composition are specific types of associations (subsets of association) representing specialized cases within the broader concept of association.</b>
<br>
<br>

<div class="image-container">
    <img src="../imgs/association.jpg">
</div>

<br>
<br>
The remaining three essential class relationships are specific form of association relationships. during development, this is exactly how
relationships tend to evolve. We first assert the existence of a semantic connection between two classes and then, as we make tactical decisions about the exact nature of their relationship, often refine them into generalization (inheritance), aggregation, or composition relationships.
<hr>

## Aggregation relationship 🔗

**Aggregation** represents a <span style="background-color: #FFFF00">"has-a"</span> relationship where one object contains another object, but the contained object can exist independently. **Aggregation is a weaker form of association**.
In aggregation the life cycle of owning object and owned object are independent. unlike a composition relationship, where death of the owning object means the death of its owned objects. aggregation allows the owned objects to persist even after the owning object ceases to exist.

### Example:

Consider a scenario where a `Library` has many `Books`. Each book is an independent entity and can exist outside the library.

### C++ Example:

```cpp
#include <iostream>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;

public:
    Book(std::string t, std::string a) : title(t), author(a) {}
};

class Library {
private:
    std::string name;
    std::vector<Book*> books;

public:
    Library(std::string n) : name(n) {}
    ~Library() {
        // It does not destroy the contained Book objects.
    }

    void addBook(const Book *book) {
        books.push_back(book);
    }
};

// Aggregation between Library and Book
int main(void) {
    Library myLibrary("City Library");
    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    Book book2("To Kill a Mockingbird", "Harper Lee");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    return (0);
}
```


<br>



## Composition relationship ⚙️

Composition is a stronger form of aggregation where one object is composed of other objects (part/whole), and the composed objects have a strong dependency on the container object. If the container is destroyed, the composed objects are also destroyed.
`Composition implies that the construction and destruction of these parts occurs as a consequence of the construction and destruction of the aggregate.`

### Example:

Imagine a situation where a `Person` is composed of vital organs like a `Heart` and a `Brain`. Each organ is essential to the person's existence, and they share a strong dependency. If the person ceases to exist, all its vital organs, including the heart and brain, also cease to function

### C++ Example:

```cpp
#include <iostream>

class Heart {
public:
    void pump() {
        std::cout << "Heart is pumping blood." << std::endl;
    }
};

class Brain {
public:
    void think() {
        std::cout << "Brain is thinking." << std::endl;
    }
};

class Person {
private:
    Heart heart;
    Brain brain;

public:
    Person() {
        // brain and heart get constructed
    }

    ~Person() {
        // brain and heart get destructed also
    }

    void live() {
        heart.pump();
        brain.think();
        std::cout << "The person is alive and functioning." << std::endl;
    }
};

int main() {
    // Composition between Person, Heart, and Brain
    Person individual;
    
    // The person lives, invoking actions of the heart and brain.
    individual.live();

    return 0;
}
```

### Difference between composition and aggregation
The difference between `composition` and `aggregation` lies in the **strength** of the relationship between the container (owning) object and the contained (owned) object.
Consider <a href="https://en.wikipedia.org/wiki/Object_composition#Aggregation">this example (wiki)</a>, Aggregation differs from ordinary composition in that it does not imply ownership. In composition, when the owning object is destroyed, so are the contained objects. In aggregation, this is not necessarily true. For example, a university owns various departments (e.g., chemistry), and each department has a number of professors. If the university closes, the departments will no longer exist, but the professors in those departments will continue to exist. Therefore, a **university can be seen as a composition of departments**, whereas **departments have an aggregation of professors**. In addition, a professor could work in more than one department, but a department could not be part of more than one university.

<br>



# Links

* <a href="https://medium.com/@bindubc/association-aggregation-and-composition-in-oops-8d260854a446">Association, aggregation, and composition in OOPs</a>
* <a href="https://medium.com/launch-school/no-object-is-an-island-707e59ffedb4">No object is an island</a>
* <a href="https://en.wikipedia.org/wiki/Object_composition#Aggregation">Object composition</a>
* <a href="https://www.codeproject.com/Articles/330447/Understanding-Association-Aggregation-and-Composit">Understanding Association, Aggregation, and Composition</a>
* <a href="https://medium.com/@daloukalai/double-dispatching-in-c-df76724cf321">Double Dispatching in C++</a>
* <a href=""></a>