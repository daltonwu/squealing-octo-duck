from bs4 import BeautifulSoup

soup = BeautifulSoup(html_doc, 'https://www.google.com/#safe=off&q=iguana')

print(soup.prettify())
