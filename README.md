Probable features for an offline tracker

Backend<br>
PDF/CSV statement parsing<br>
metadata basaed transaction filtering<br>
rich analytics <br>
transaction categorization and sorting (service type i.e. Food, Groceries, Fuel, Services, Subscriptions, Streaming, etc)<br>
(add more as ideas come)<br>
BONUS: Fully offline AI LLM that works with data offline to answer custom user queries (need to ensure zero network leaks)<br>

Frontend:<br>
account-by-account view with expandable/collapsible tables for each account with balance trendline<br>
overall view with totals across accounts (adding up networth essentially)<br>
transaction view mode<br>
(need more suggestions)<br>
<br>
<br>
Stack<br>
UI: Qt<br>
DB: SQLite<br>
OBJ Store: Boost.Serialization<br>
Data Visualization: QCustomPlot<br>
Encryption: Crypto++<br>
Test: Google Test<br>
Style Guide (STRICTLY ENFORCED): Google C++ Style Guide - https://google.github.io/styleguide/cppguide.html<br>
Git Structure: Trunk Based - https://www.atlassian.com/continuous-delivery/continuous-integration/trunk-based/development<br>
<br>
Main trunk integration via: Pull Requests<br>
Programming Style: OOP<br>
