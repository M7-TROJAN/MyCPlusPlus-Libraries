## System Architecture 

### sub Section Title: **Background Job: Notification Services**

###  Overview:

The system includes two scheduled background jobs implemented via **Hangfire**, responsible for sending automated notifications to users via **Email** and **WhatsApp**, in two critical scenarios:

1. **Subscription Expiration Reminders**
2. **Rental Due Reminders**

---

###  1. Subscription Expiration Notification

* **Trigger:** Daily
* **Target Users:** Subscribers whose subscription ends in **5 days**
* **Channel:** Email + WhatsApp (if registered)
* **Email Template:** `SubscriptionExpirationReminder`
* **WhatsApp Template:** Same name
* **Personalization:** Includes user name and expiration date

####  Example Message (Email):

> Hello Sarah,
> Your subscription is set to expire on 20 May, 2025. 😔
> Renew now to continue enjoying our services without interruption.

---

###  2. Rental Expiration Reminder

* **Trigger:** Daily
* **Target Users:** Subscribers who have book copies that expire **tomorrow**
* **Channel:** Email + WhatsApp
* **Email Template:** `Notification`
* **WhatsApp Template:** `RentalExpirationAlert`
* **Personalization:** User name, expiration date, list of book titles

####  Example Message (Email):

> Hello Ahmed,
> Your rental for the below book(s) will expire by tomorrow 15 May, 2025 :
>
> * Clean Code
> * Atomic Habits
>
>  Please return them on time to avoid any late fees.

---

###  Technologies Used:

| Feature          | Implementation                       |
| ---------------- | ------------------------------------ |
| Job Scheduling   | [Hangfire](https://www.hangfire.io/) |
| Email Sending    | `IEmailSender`, with HTML Templates  |
| WhatsApp Sending | Custom `IWhatsAppClient` integration |
| Template Engine  | Placeholder-based dynamic HTML       |

---

###  Execution Logic Summary

* The jobs run **asynchronously** and in parallel to reduce latency using `Task.WhenAll()`.
* If the app is in development mode, all messages are redirected to a **test phone number**.
* Template components are rendered dynamically depending on the **user’s name** and **due data**.

---
