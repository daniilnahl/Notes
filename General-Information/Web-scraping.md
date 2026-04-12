# What is Web Scraping?
Basically extracting information from a website to be put into a .csv or json file or some database for X or Y reason. Depending on the website that is being scraped it could be easy or difficult:
- **EASY:** static or lightly dynamic sites.
- **DIFFICULT:** JavaScript website with rendered pages, images, block bots, etc. 

Another important point is that with time websites get updated and the old software I/you wrote gets broken.


# How to do Web Scraping?
There are a few ways:
1. Using pre-builts tools and APIs, useful for complex projects where some abstractions is helpful, but not very useful when I am trying to learn something.
2. Manually writing a web-scraper algorithm. *How does this work?*
    1. A URL is taken and all HTML code from is collected.
    2. Then the scraper algorithm collects all the necessary data from that html code.
    