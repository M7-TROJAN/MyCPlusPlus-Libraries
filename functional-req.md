### Functional Requirements

| Identifier | Priority | Requirement                                                                                                                                  |
| ---------- | -------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| REQ1       | High     | The system shall allow anonymous users to search for books.                                                                                  |
| REQ2       | High     | The system shall allow anonymous users to find a specific book.                                                                              |
| REQ3       | High     | The system shall display book details and available copies to anonymous users.                                                               |
| REQ4       | Medium   | The system shall allow anonymous users to navigate to the Login Page.                                                                        |
| REQ5       | High     | The system shall validate user email and password during login.                                                                              |
| REQ6       | High     | The system shall display an error message when email or password is incorrect.                                                               |
| REQ7       | High     | The system shall check the user role and authorize access accordingly.                                                                       |
| REQ8       | Low      | The system shall remember login credentials if the user opts for it.                                                                         |
| REQ9       | Low      | The system shall allow the user to toggle password visibility.                                                                               |
| REQ10      | High     | The system shall allow users to reset their password if forgotten.                                                                           |
| REQ11      | High     | The system shall send a password reset link to the user’s email.                                                                             |
| REQ12      | High     | The system shall validate email, password, and confirm password fields during reset.                                                         |
| REQ13      | High     | The system shall redirect users to Home Page after successful login.                                                                         |
| REQ14      | Medium   | The system shall allow users to access account settings.                                                                                     |  
| REQ15      | Low      | The system shall allow users to Add, update or remove their profile cover image.                                                             |
| REQ17      | Medium   | The system shall allow users to update their profile details.                                                                                |
| REQ18      | High     | The system shall display validation messages for incorrect profile inputs.                                                                   |
| REQ19      | Medium   | The system shall allow users to change their email address.                                                                                  |
| REQ20      | Medium   | The system shall send a verification email for updated email addresses.                                                                      |
| REQ21      | Medium   | The system shall confirm the new email after user verification.                                                                              |
| REQ22      | Medium   | The system shall allow users to change their password.                                                                                       |
| REQ23      | Medium   | The system shall notify the user via email after password change.                                                                            |
| REQ24      | Medium   | The system shall allow users to enable two-factor authentication.                                                                            |
| REQ25      | Medium   | The system shall send a 6-digit code to confirm enabling two-factor authentication.                                                          |
| REQ26      | Medium   | The system shall log out the user after successful 2FA code entry.                                                                           |
| REQ27      | Medium   | The system shall send a new 6-digit code for confirmation when needed.                                                                       |
| REQ28      | Medium   | if two-factor is enable The system shall prompt the user to enter the 2FA code after login.                                                  |
| REQ29      | Medium   | The system shall allow users to disable two-factor authentication.                                                                           |
| REQ30      | Medium   | The system shall log out users after disabling two-factor authentication.                                                                    |
| REQ31      | High     | The system shall allow archive staff to search for any category in the database.                                                             |
| REQ32      | High     | The system shall allow archive staff to add new categories.                                                                                  |
| REQ33      | High     | The system shall validate category name uniqueness and display an error if it already exists.                                                |
| REQ34      | High     | The system shall allow archive staff to edit any existing category.                                                                          |
| REQ35      | High     | The system shall allow archive staff to delete any category.                                                                                 |
| REQ36      | Medium   | The system shall allow archive staff to export category data as PDF, Excel and CSV.                                                          |
| REQ37      | Low      | The system shall allow archive staff to copy category table content to the clipboard.                                                        |
| REQ38      | Medium   | The system shall allow archive staff to print the content of the category table.                                                             |
| REQ39      | High     | The system shall allow archive staff to search for any author in the database.                                                               |
| REQ40      | High     | The system shall allow archive staff to add new authors.                                                                                     |
| REQ41      | High     | The system shall validate author name uniqueness and show an error if duplicated.                                                            |
| REQ42      | High     | The system shall allow archive staff to edit any existing author.                                                                            |
| REQ43      | High     | The system shall allow archive staff to delete any author.                                                                                   |
| REQ44      | Medium   | The system shall allow archive staff to export author data as PDF, Excel and CSV.                                                            |
| REQ45      | Low      | The system shall allow archive staff to copy author table content.                                                                           |
| REQ46      | Medium   | The system shall allow archive staff to print the author table.                                                                              |
| REQ47      | High     | The system shall allow archive staff to search for any book in the database.                                                                 |
| REQ48      | High     | The system shall allow archive staff to add new books.                                                                                       |
| REQ49      | High     | The system shall validate book title and author combination for uniqueness.                                                                  |
| REQ50      | Medium   | The system shall allow archive staff to add, update or remove book cover images.                                                             |
| REQ51      | High     | The system shall allow archive staff to update book details.                                                                                 |
| REQ52      | Medium   | The system shall allow enabling rental availability for books.                                                                               |
| REQ53      | High     | The system shall allow archive staff to view details of any book.                                                                            |
| REQ54      | High     | The system shall allow archive staff to add copies for books.                                                                                |
| REQ55      | High     | The system shall allow archive staff to edit book copies.                                                                                    |
| REQ56      | High     | The system shall allow archive staff to delete book copies.                                                                                  |
| REQ57      | High     | The system shall allow archive staff to delete any book.                                                                                     |
| REQ58      | Medium   | The system shall allow archive staff to export book data as PDF, Excel and CSV.                                                              |
| REQ59      | Low      | The system shall allow archive staff to copy book table content.                                                                             |
| REQ60      | Medium   | The system shall allow archive staff to print the book table.                                                                                |
| REQ61      | High     | The system shall allow receptionists to search for any subscriber.                                                                           |
| REQ62      | High     | The system shall allow receptionists to add new subscribers.                                                                                 |
| REQ63      | High     | The system shall allow receptionists to view subscriber details.                                                                             |
| REQ64      | High     | The system shall allow receptionists to renew subscriptions by one year.                                                                     |
| REQ65      | Medium   | The system shall allow receptionists to view subscriber overviews.                                                                           |
| REQ66      | Medium   | The system shall allow receptionists to view subscriber rental records.                                                                      | 
| REQ67      | Medium   | The system shall show the number of rentals per subscriber.                                                                                  |
| REQ68      | Medium   | The system shall send a confirmation email upon successful subscription.                                                                     |
| REQ69      | Medium   | The system shall allow receptionists to view past rentals.                                                                                   |
| REQ70      | Medium   | The system shall display rental info including delay days, start date, and book copies.                                                      |
| REQ71      | High     | The system shall allow receptionists to create new rentals.                                                                                  |
| REQ72      | High     | The system shall check for existing valid rentals and prevent new ones if present.                                                           |
| REQ73      | High     | The system shall allow searching books during rental creation.                                                                               |
| REQ74      | Medium   | The system shall allow adding/removing books in a rental before saving.                                                                      |
| REQ75      | High     | The system shall ensure rentals do not exceed 3 books.                                                                                       |
| REQ76      | High     | The system shall display an error if rental exceeds 3 books.                                                                                 |
| REQ77      | Medium   | The system shall allow cancelling/editing rentals within 24 hours.                                                                           |
| REQ78      | Medium   | The system shall allow extending rentals by 7 days after 24 hours.                                                                           |
| REQ79      | High     | The system shall allow admin to search for users.                                                                                            |
| REQ80      | Medium   | The system shall allow sorting user data by ascending or descending.                                                                         |
| REQ81      | High     | The system shall allow admin to add new users.                                                                                               |
| REQ82      | High     | The system shall validate user inputs and show errors for missing/invalid data.                                                              |
| REQ83      | Medium   | The system shall send an email notification upon adding a new user.                                                                          |
| REQ84      | High     | The system shall allow admin to edit all users except super admins.                                                                          |
| REQ85      | High     | The system shall allow super admin to edit super admin account.                                                                              |
| REQ86      | Medium   | The system shall allow admin to reset users passwords.                                                                                       |
| REQ87      | Medium   | The system shall allow admin to lock users accounts.                                                                                         |
| REQ88      | Medium   | The system shall allow admin to unlock users accounts.                                                                                       |
| REQ89      | Medium   | The system shall allow admin to delete users.                                                                                                | 
| REQ90      | Medium   | The system shall allow admin to export users data as PDF, Excel and CSV.                                                                     |
| REQ91      | Low      | The system shall allow admin to copy users table content.                                                                                    |
| REQ92      | Medium   | The system shall allow admin to print the users table.                                                                                       |
| REQ93      | High     | The system shall allow The Super Admin to have full access to perform any operation that is permitted to other user roles across the system. |
| REQ94      | Medium   | The system shall allow just super admin to view the subscribers list.                                                                        |
