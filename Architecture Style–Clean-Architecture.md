
### Architecture Style:

### **2.1 Architecture Style – Clean Architecture**

#### **Overview**

The system is designed using **Clean Architecture**, a software design pattern that promotes separation of concerns, scalability, and maintainability. The architecture ensures that core business logic remains independent of UI, database, and external frameworks.

Unlike traditional MVC architectures where all layers exist in a single project, our solution is structured into **4 separate projects**:

---

### **Solution Structure**

| Project Name                 | Responsibility                                                                    |
| ---------------------------- | --------------------------------------------------------------------------------- |
| **LitraLand.Domain**         | Contains the core domain models and interfaces. No external dependencies.         |
| **LitraLand.Application**    | Contains the application logic, use cases, DTOs, and service contracts.           |
| **LitraLand.Infrastructure** | Implements the interfaces in Domain and Application (e.g., EF Core Repositories). |
| **LitraLand.Web**            | The MVC Web application that contains Controllers, Views, and handles UI/UX.      |

---

### **Clean Architecture Layers**

#### 1. **Domain Layer**

Contains entities, enums, and interfaces.
**No dependency on any other project.**

#### 2. **Application Layer**

Contains use case logic (e.g., services, view models).
Depends **only** on the Domain layer.

#### 3. **Infrastructure Layer**

Implements the interfaces in the Application and Domain layers.
Depends on both Application and Domain layers.

#### 4. **Web Layer (Presentation)**

Handles all MVC components (Controllers, Views, Razor Pages).
Depends on Application and Infrastructure.

---

### **Diagram: Clean Architecture in LitraLand**

```
         [ Presentation (LitraLand.Web) ]
                      |
         ------------------------------
         |                            |
 [ Application Layer ]        [ Infrastructure Layer ]
         |                            |
         ------------------------------
                      |
               [ Domain Layer ]
```

---

### **Clean Architecture VS Traditional MVC **

| Aspect                 | Traditional MVC | Clean Architecture in LitraLand     |
| ---------------------- | --------------- | ----------------------------------- |
| Structure              | Single Project  | Multiple Projects (Layered)         |
| Separation of Concerns | Limited         | Strong Separation                   |
| Testability            | Medium          | High                                |
| Maintainability        | Medium          | High                                |
| Dependencies           | All in one      | Core domain has **no** dependencies |

---
