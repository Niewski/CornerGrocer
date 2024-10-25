<h2>Summarize the project and what problem it was solving.</h2>
<p>
  This is a console app that read a text file containing a list of produce that sold that day, followed by the frequency of those sales. This is meant for an admin to be able to search by item, list all items, or display a histogram of sale frequency.
</p>
<h2>What did you do particularly well?</h2>
<p>
  I did a good job keeping the application modular, with concerns well separated. Reusable functions are kept in a utility file, and the classes that were created could be easily made into base classes that are inherited if more functionality is wanted later. 
</p>
<h2>Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?</h2>
<p>
  The data import could use many improvements. The data being imported should be previewed and approved by the user. The data should be backed up to a database. The data is supposed to be for a given day, so there should be a date in the file, which should be verified to see if it has been imported before.
</p>
<h2>Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?</h2>
<p>
  Implementing a case insensitive search using the map was difficult. I needed to avoid the O(n) solution where we iterate through each item, as that removed the benefits I wanted to gain from using a map. 
  This is very easy to do in higher level languages, but there is no function available in C++. AFter some research I found that I had to create a custom hash and compare function, which I could then add to the map.
</p>
<h2>What skills from this project will be particularly transferable to other projects or course work?</h2>
<p>
  I gained a better understanding of how to implement some of the methods that I am used to always having available in C#, and I am better prepared to implement those methods in lower level languages in the future.
</p>
<h2>How did you make this program maintainable, readable, and adaptable?</h2>
<p>
  I ensured that the classes and libraries I created were well named. I also made use of enumerations and constant strings to keep menu text and options centralized. Classes could easily be refactored into base classes that are inheritied. 
  For example Menu could become an abstract class, and then you can create SalesMenu, StockMenu, etc.
</p>
