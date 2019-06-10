import os
import yaml
import datetime
from rake_nltk import Rake
from bs4 import BeautifulSoup
from markdown import markdown
import re
path = os.path.join(os.getcwd(), '_posts')
print(path)
print('Enter the category : ', end='')
category = input()
print('Enter the name of the file: ', end='')
name = input()
print("was it created today ?? type 'yes' if true : ", end='')
check = input()
date=''
if check == 'yes' :
    x = datetime.datetime.now()
    date = str(x.year)
    if x.month<10:
        date = date + '-0' + str(x.month)
    else:
        date = date + '-' + str(x.month)
    if x.day < 10:
        date = date +'-0' + str(x.day)
    else:
        date = date + '-' + str(x.day)
else:
    print('Enter the date when it was created :', end='')
    date = input()
post = open(path+'/'+category+'/'+date+'-'+name)
contents = post.readlines()
count = 0
matter = ''
for content in contents:
    if content.rstrip() == '---' and count < 2 :
        count += 1
    elif count == 2:
        matter = matter + content
html1 = markdown(matter)
car =  ''.join(BeautifulSoup(html1, "html.parser").findAll(text=True))
soup = BeautifulSoup(car, 'html.parser')
car = soup.get_text()
# print(car)
car =  re.sub('[^ a-zA-Z0-9-_*.]', ' ', car)
# print(car)
r = Rake(min_length=1, max_length=2)
r.extract_keywords_from_text(car)
ranked = r.get_ranked_phrases_with_scores()
ranked.sort(key=lambda x: x[1])
# for rank in ranked:
#     print(rank[1])
tags='tags:'
for rank in ranked:
    tags = tags+  '\n- name: ' +rank[1]+  '\n'  +  '  score: '   + str(rank[0])
tags = tags+'\n'
contents.insert(1,tags)
post.close()
post = open(path+'/'+category+'/'+date+'-'+name,'w');
post.writelines(contents)
post.close()
