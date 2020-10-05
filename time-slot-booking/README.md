# Time Slot Booking

We are asked to to develop a booking application that allows customer to book medical visits. The customer is not allowed to book a visit at any time choosing the date and the time of the visit. He can choose a visit from a predefined set of visits, scheduled on different days with regularity.

Our goal is to design a time slot booking application. The application must be able generate a sequence of bookable time slot based on some criteria. A time slot is ideally identified by two dates: begin and stop date. For example (05/10/2020 16:00:00, 05/10/2020 17:00:00) is a time slot of 1h.

## Application Features

### Generate sequences of time slot

Sometimes we may need to generate a sequence of time slots subject to some constraints.

_Example_. Generate a sequence of bookable time slots with this constraints

- given a time slot _ts_, it's length is 30 minutes. Formally, |_ts_| = 30|;
- given two time slots _ts1_ and _ts2_, they cannot overlap. Formally _ts1_ not /\ _ts2_;
- given a time slot _ts_ it cannot start before 8:00 AM, and it cannot finish afetr 12:00 AM

### Book a time slot

At the end we may also need to book one time slot from a sequence of time slot.
