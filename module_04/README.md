# Design Pattern

## Education Managamrent system
<img src="../imgs/school_diagram.png">

This diagram encapsulates the intricate relationships within an Education Management System. At its core is the Person base class, extending to specialized roles such as Student, Professor, Secretary, and HeadMaster. Importantly, both Secretary and Professor are designated as staff members, emphasizing their pivotal roles in the educational ecosystem. The HeadMaster also assumes a staff position, contributing to the administrative aspects of the system.

Parallelly, the Room base class orchestrates the aggregation of individuals within defined spaces. Subclasses such as Classroom and SecretarialOffice extend this hierarchy, aligning with distinct functionalities.

A critical element within the system is the Form class, intimately associated with subclasses of Staff. These staff members, including Secretary, Professor, and HeadMaster, are entrusted with the validation and execution of forms, which are subsequently stored within the SecretarialOffice.
Lastly, the Course class plays a pivotal role, encompassing a list of enrolled students, the responsible professor, and the associated classroom for the course.

## Singleton Design pattern

Singleton design pattern is a creational design pattern that ensures a class has only one instance and provides a global point of access to that instance. In other words, it restricts the instantiation of a class to a single object, which can be accessed from anywhere in the application. This pattern is commonly used when you need to manage a shared resource, configuration settings, or a global state in a controlled manner.

<br>

<img src="../imgs/singleton_uml.png">


### Intent
* Ensure that only one instance of a class is created.
* Provide a global point of access to the object

the problem that Singleton solve is when application needs **one**, and only one, instance of an object. Additionally, **lazy initialization** and **global access** are necessary.

## Implementation
The implementation involves a static member in the Singleton class which keeps the reference to the instance, a private constructor and a static public method that returns the static member reference.

<img src="../imgs/singleton2.png">


# Links
<a href="https://www.oodesign.com/singleton-pattern">Singleton design pattern (OODesign)</a>
<br>
<a href="https://medium.com/geekculture/overview-of-singleton-design-pattern-10b2b18bfd11">Singleton design pattern</a>
<br>
<a hre="https://medium.com/@leogbastiani/singleton-vs-global-variables-choosing-the-best-structure-for-your-code-ed25aec3e9f9">Singleton vs global variables</a>
<br>
https://www.youtube.com/watch?v=hUE_j6q0LTQ