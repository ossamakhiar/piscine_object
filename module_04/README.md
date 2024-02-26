# Design Pattern

## Education Managamrent system
<img src="../imgs/school_diagram.png">

This diagram encapsulates the intricate relationships within an Education Management System. At its core is the Person base class, extending to specialized roles such as Student, Professor, Secretary, and HeadMaster. Importantly, both Secretary and Professor are designated as staff members, emphasizing their pivotal roles in the educational ecosystem. The HeadMaster also assumes a staff position, contributing to the administrative aspects of the system.

Parallelly, the Room base class orchestrates the aggregation of individuals within defined spaces. Subclasses such as Classroom and SecretarialOffice extend this hierarchy, aligning with distinct functionalities.

A critical element within the system is the Form class, intimately associated with subclasses of Staff. These staff members, including Secretary, Professor, and HeadMaster, are entrusted with the validation and execution of forms, which are subsequently stored within the SecretarialOffice.
Lastly, the Course class plays a pivotal role, encompassing a list of enrolled students, the responsible professor, and the associated classroom for the course.

