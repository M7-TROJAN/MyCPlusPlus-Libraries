2.1 Architecture Style

2.1.1 Clean Architecture

The system architecture of LitraLand follows the Clean Architecture style. This pattern organizes the system into well-defined layers with one-way dependency rules, which enhances modularity, testability, and maintainability.

[Insert Architecture Diagram Here]

As shown in the architecture diagram, the system is divided into four main layers:
	•	Domain Layer (LitraLand.Domain):
Contains the core business entities, enums, and interfaces. It is the innermost and most independent layer with no dependencies on other layers.
	•	Application Layer (LitraLand.Application):
Contains application logic, service contracts, use cases, and validations. It only depends on the Domain layer.
	•	Infrastructure Layer (LitraLand.Infrastructure):
Provides implementations for interfaces defined in the Domain or Application layers. Examples include database access, email services, file handling, etc. This layer depends on the inner layers but is not depended on by them.
	•	Presentation Layer (LitraLand.Web):
An ASP.NET Core MVC project responsible for the user interface and request handling. It communicates with the Application layer to process logic and present output.

Dependency Flow:
Dependencies always point inward. Outer layers depend on inner layers, ensuring that business logic is completely isolated from external concerns.

⸻

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

The Presentation Layer (LitraLand.Web) follows the Model-View-Controller (MVC) design pattern, which separates the system into:
	•	Model:
Contains data models and view models used to transfer data between controllers and views.
	•	View:
Renders HTML output using Razor templates.
	•	Controller:
Handles incoming HTTP requests, interacts with the Application layer, and returns appropriate views or responses.

This pattern improves maintainability, scalability, and testability by decoupling the user interface from the business logic.

⸻

2.1.3 Areas Structure

To improve modularity and better manage the system’s features, the Presentation Layer is organized into three main Areas:
	•	Identity Area:
Responsible for user authentication and account-related operations such as login, registration, password reset, email verification, and two-factor authentication.
	•	Library Area:
Handles core library functionalities including categories, authors, books, copies, rentals, and subscribers. It is primarily used by staff roles such as Archive and Receptionist.
	•	Community Area:
Offers a social platform for users to interact, view other users’ books, and manage personal listings for book exchange or sale. Users can create profiles and browse books shared by others.

This area-based structure helps in isolating features, simplifying routing, and scaling individual sections independently.

⸻
[Insert MVC Diagram Here]