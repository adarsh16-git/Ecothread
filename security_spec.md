# EcoThread Security Specification

## Data Invariants
1. A Product must have a title, price, type, and images.
2. A Product's `sellerId` must match the authenticated `request.auth.uid`.
3. A Chat must include the current user in `participantIds`.
4. A Message must belong to a Chat where the sender is a participant.
5. Users can only edit their own profile.
6. Product price must be a positive number.

## The Dirty Dozen Payloads (Rejection Targets)
1. **Identity Spoofing**: Creating a product with `sellerId: "other-user-id"`.
2. **State Shortcutting**: Updating a product's `status` to "sold" when not the owner.
3. **Price Manipulation**: Setting a product's price to `-50`.
4. **Admin Escalation**: Attempting to set `isAdmin: true` on user profile.
5. **Unauthorized Chat Reading**: Accessing `/chats/non-owned-chat-id`.
6. **Relational Sync Failure**: Creating a message in a chat not belonging to the user.
7. **Ghost Fields**: Adding `verified: true` to a product listing update.
8. **PII Leak**: Reading another user's email directly from `/users`.
9. **ID Poisoning**: Injecting 2kb string as a product ID.
10. **Timestamp Fraud**: Setting `createdAt` to a future date instead of `request.time`.
11. **Type Poisoning**: Sending `images: "not-an-array"`.
12. **Orphaned Writes**: Creating a message in a non-existent chat.
