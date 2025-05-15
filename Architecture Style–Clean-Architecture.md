
### Architecture Style:

⸻

2.1 Architecture Style

2.1.1 Clean Architecture

The system architecture of LitraLand follows the Clean Architecture style. This pattern organizes the system into clear layers with one-way dependency rules, making the application modular, testable, and maintainable.

هنحط هنا الدياجرام الرسمة بتاعت الدواير الي قولتلك اعملها يامصطفي 

As shown in the architecture diagram, the system consists of four main layers:
	•	Domain Layer (LitraLand.Domain):
Contains the core business entities, enums, and interfaces. It is the innermost and most isolated layer, independent from all others.
	•	Application Layer (LitraLand.Application):
Contains application logic, service contracts, use cases, and validation. It depends only on the Domain layer.
	•	Infrastructure Layer (LitraLand.Infrastructure):
Provides implementations for interfaces defined in the Domain or Application layers, such as database access, email services, file storage, etc. It depends on the inner layers but is not depended on by them.
	•	Presentation Layer (LitraLand.Web):
An ASP.NET Core MVC project responsible for the UI and request handling. It interacts with the Application layer to process logic and present results.

Dependency Flow:
Dependencies always point inward — outer layers depend on inner layers. This ensures separation of concerns and keeps the business logic isolated.

### **Solution Structure**

| Project Name                 | Responsibility                                                                    |
| ---------------------------- | --------------------------------------------------------------------------------- |
| **LitraLand.Domain**         | Contains the core domain models and interfaces. No external dependencies.         |
| **LitraLand.Application**    | Contains the application logic, use cases, DTOs, and service contracts.           |
| **LitraLand.Infrastructure** | Implements the interfaces in Domain and Application (e.g., EF Core Repositories). |
| **LitraLand.Web**            | The MVC Web application that contains Controllers, Views, and handles UI/UX.      |


### **Clean Architecture VS Traditional MVC **

| Aspect                 | Traditional MVC | Clean Architecture in LitraLand     |
| ---------------------- | --------------- | ----------------------------------- |
| Structure              | Single Project  | Multiple Projects (Layered)         |
| Separation of Concerns | Limited         | Strong Separation                   |
| Testability            | Medium          | High                                |
| Maintainability        | Medium          | High                                |
| Dependencies           | All in one      | Core domain has **no** dependencies |

---

⸻

2.1.2 Model View Controller (MVC)

The Presentation Layer (LitraLand.Web) is built using the Model-View-Controller (MVC) pattern, which separates the application into:
	•	Model:
Contains the data and view models used to transfer data between the controller and the view.
	•	View:
Displays data to the user using Razor templates.
	•	Controller:
Handles user requests, calls services from the Application layer, processes business logic, and returns appropriate views or JSON results.

MVC allows for better separation of responsibilities and enhances the testability and organization of the application code.

⸻

2.1.3 Areas Structure

To improve modularity, separation of features, and ease of management, the Presentation Layer is organized into three main areas:
	•	Identity Area:
Handles user authentication and account management functionalities, such as registration, login, password reset, email verification, and two-factor authentication.
	•	Library Area:
Manages all core library functionalities, including books, categories, authors, book copies, rentals, and subscribers. It is accessible to roles like Archive and Receptionist.
	•	Community Area:
Provides a social space for users to interact, share books, and manage their personal book listings for exchange or sale. Each user has a personal profile and can browse other users’ offerings.

This separation into areas improves scalability and makes it easier to manage large features in isolation while keeping the routing, views, and controllers organized.

⸻

هنحط هنا الدياجرام بتاع ال mvc الي احنا واخدينه من الدكيومنتيشن القديمة





