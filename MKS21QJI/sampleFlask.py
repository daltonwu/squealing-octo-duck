from flask import Flask, render_template

app = Flask(__name__)

@app.route('/lucky')
def lucky():
	import random
	number = random.randrange(1,100)
	return '<h1>Lucky number: %d</h1>'%(number)

@app.route('/about')
def about():
	page = '''
<h1>About</h1>
<hr>
<ol>
	<li>Fred Flintstone</li>
	<li>Mr. T</li>
	<li>The Hulk</li>
</ol>
'''
	return templates('about.html')

@app.route("/")
@app.route("/home")
def kerfuffle():
	return "<h1>Hello, world!</h1>"

if __name__=="__main__":
	app.debug = True
	app.run(host='0.0.0.0',port=8000)
