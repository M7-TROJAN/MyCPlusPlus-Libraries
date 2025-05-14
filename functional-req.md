### Functional Requirements

| Identifier | Priority | Requirement                                                                                   |
| ---------- | -------- | --------------------------------------------------------------------------------------------- |
| REQ1       | High     | The system shall allow anonymous users to find books.                                         |
| REQ2       | High     | The system shall allow anonymous users to search for books.                                   |
| REQ3       | High     | The system shall display book details and available copies to anonymous users.                |
| REQ4       | Medium   | The system shall allow anonymous users to navigate to the dashboard.                          |
| REQ5       | High     | The system shall validate user email and password during login.                               |
| REQ6       | High     | The system shall display an error message when email or password is incorrect.                |
| REQ7       | High     | The system shall check the user role and authorize access accordingly.                        |
| REQ8       | Low      | The system shall remember login credentials if the user opts for it.                          |
| REQ9       | Low      | The system shall allow the user to toggle password visibility.                                |
| REQ10      | High     | The system shall allow users to reset their password if forgotten.                            |
| REQ11      | High     | The system shall send a password reset link to the user’s email.                              |
| REQ12      | High     | The system shall validate email, password, and confirm password fields during reset.          |
| REQ13      | High     | The system shall redirect users to the dashboard after successful login.                      |
| REQ14      | Medium   | The system shall allow users to access account settings.                                      | 
| REQ15      | Low      | The system shall allow users to remove their profile cover image.                             |
| REQ16      | Low      | The system shall allow users to update their profile cover image.                             |
| REQ17      | Medium   | The system shall allow users to update their profile details.                                 |
| REQ18      | High     | The system shall display validation messages for incorrect profile inputs.                    |
| REQ19      | Medium   | The system shall allow users to change their email address.                                   |
| REQ20      | Medium   | The system shall send a verification email for updated email addresses.                       |
| REQ21      | Medium   | The system shall confirm the new email after user verification.                               |
| REQ22      | Medium   | The system shall allow users to change their password.                                        |
| REQ23      | Medium   | The system shall notify the user via email after password change.                             |
| REQ24      | Medium   | The system shall allow users to enable two-factor authentication.                             |
| REQ25      | Medium   | The system shall send a 6-digit code to confirm enabling two-factor authentication.           |
| REQ26      | Medium   | The system shall log out the user after successful 2FA code entry.                            |
| REQ27      | Medium   | The system shall send a new 6-digit code for confirmation when needed.                        |
| REQ28      | Medium   | The system shall prompt the user to enter the 2FA code after login.                           |
| REQ29      | Medium   | The system shall allow users to disable two-factor authentication.                            |
| REQ30      | Medium   | The system shall log out users after disabling two-factor authentication.                     |
| REQ31      | High     | The system shall allow archive staff to search for any category in the database.              |
| REQ32      | High     | The system shall allow archive staff to add new categories.                                   |
| REQ33      | High     | The system shall validate category name uniqueness and display an error if it already exists. |
| REQ34      | High     | The system shall allow archive staff to edit any existing category.                           |
| REQ35      | High     | The system shall allow archive staff to delete any category.                                  |
| REQ36      | Medium   | The system shall allow archive staff to export category data as PDF.                          |
| REQ37      | Medium   | The system shall allow archive staff to export category data as Excel.                        |
| REQ38      | Medium   | The system shall allow archive staff to export category data as CSV.                          |
| REQ39      | Low      | The system shall allow archive staff to copy category table content.                          |
| REQ40      | Medium   | The system shall allow archive staff to print the category table.                             |
| REQ41      | High     | The system shall allow archive staff to search for any author in the database.                |
| REQ42      | High     | The system shall allow archive staff to add new authors.                                      |
| REQ43      | High     | The system shall validate author name uniqueness and show an error if duplicated.             |
| REQ44      | High     | The system shall allow archive staff to edit any existing author.                             |
| REQ45      | High     | The system shall allow archive staff to delete any author.                                    |
| REQ46      | Medium   | The system shall allow archive staff to export author data as PDF.                            |
| REQ47      | Medium   | The system shall allow archive staff to export author data as Excel.                          |
| REQ48      | Medium   | The system shall allow archive staff to export author data as CSV.                            |
| REQ49      | Low      | The system shall allow archive staff to copy author table content.                            |
| REQ50      | Medium   | The system shall allow archive staff to print the author table.                               |
| REQ51      | High     | The system shall allow archive staff to search for any book in the database.                  |
| REQ52      | High     | The system shall allow archive staff to add new books.                                        |
| REQ53      | High     | The system shall validate book title and author combination for uniqueness.                   |
| REQ54      | Medium   | The system shall allow archive staff to add or remove book cover images.                      |
| REQ55      | High     | The system shall allow archive staff to update book details and covers.                       |
| REQ56      | Medium   | The system shall allow enabling rental availability for books if permitted.                   |
| REQ57      | High     | The system shall allow archive staff to view details of any book.                             |
| REQ58      | High     | The system shall allow archive staff to add copies for books.                                 |
| REQ59      | High     | The system shall allow archive staff to edit book copies.                                     |
| REQ60      | High     | The system shall allow archive staff to delete book copies.                                   |
| REQ61      | High     | The system shall allow archive staff to delete any book.                                      |
| REQ62      | Medium   | The system shall allow archive staff to export book data as PDF.                              |
| REQ63      | Medium   | The system shall allow archive staff to export book data as Excel.                            |
| REQ64      | Medium   | The system shall allow archive staff to export book data as CSV.                              |
| REQ65      | Low      | The system shall allow archive staff to copy book table content.                              |
| REQ66      | Medium   | The system shall allow archive staff to print the book table.                                 |
| REQ67      | High     | The system shall allow receptionists to search for any subscriber.                            |
| REQ68      | High     | The system shall allow receptionists to add new subscribers.                                  |
| REQ69      | Medium   | The system shall allow super admin to view the subscriber list.                               |
| REQ70      | High     | The system shall allow receptionists to view subscriber details.                              |
| REQ71      | High     | The system shall allow receptionists to renew subscriptions by one year.                      |
| REQ72      | Medium   | The system shall allow receptionists to view subscriber overviews.                            |
| REQ73      | Medium   | The system shall allow receptionists to view subscriber rental records.                       |
| REQ74      | Medium   | The system shall show the number of rentals per subscriber.                                   |
| REQ75      | Medium   | The system shall send a confirmation email upon successful subscription.                      |
| REQ76      | Medium   | The system shall allow receptionists to view past rentals.                                    |
| REQ77      | Medium   | The system shall display rental info including delay days, start date, and book copies.       |
| REQ78      | High     | The system shall allow receptionists to create new rentals.                                   |
| REQ79      | High     | The system shall check for existing valid rentals and prevent new ones if present.            |
| REQ80      | High     | The system shall allow searching books during rental creation.                                |
| REQ81      | Medium   | The system shall allow adding/removing books in a rental before saving.                       |
| REQ82      | High     | The system shall ensure rentals do not exceed 3 books.                                        |
| REQ83      | High     | The system shall display an error if rental exceeds 3 books.                                  |
| REQ84      | Medium   | The system shall allow cancelling/editing rentals within 24 hours.                            |
| REQ85      | Medium   | The system shall allow extending rentals by 7 days after 24 hours.                            |
| REQ86      | High     | The system shall allow admin to search for users.                                             |
| REQ87      | Medium   | The system shall allow sorting user data by ascending or descending.                          |
| REQ88      | High     | The system shall allow admin to add new users.                                                |
| REQ89      | High     | The system shall validate user inputs and show errors for missing/invalid data.               |
| REQ90      | Medium   | The system shall send an email notification upon adding a new user.                           |
| REQ91      | High     | The system shall allow admin to edit all users except super admins.                           |
| REQ92      | High     | The system shall allow super admin to edit super admin account.                               |
| REQ93      | Medium   | The system shall allow admin to reset user passwords.                                         |
| REQ94      | Medium   | The system shall allow admin to lock user accounts.                                           |
| REQ95      | Medium   | The system shall allow admin to unlock user accounts.                                         |
| REQ96      | Medium   | The system shall allow admin to delete users.                                                 |
| REQ97      | Medium   | The system shall allow admin to export user data as PDF.                                      |
| REQ98      | Medium   | The system shall allow admin to export user data as Excel.                                    |
| REQ99      | Medium   | The system shall allow admin to export user data as CSV.                                      |
| REQ100     | Low      | The system shall allow admin to copy user table content.                                      |
| REQ101     | Medium   | The system shall allow admin to print the user table.                                         |
| REQ102     | High     | The system shall allow users to search for books and view their details and available copies. |
