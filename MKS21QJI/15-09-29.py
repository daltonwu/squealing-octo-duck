from flask import Flask, render_template, session, redirect, url_for

app = Flask(__name__)

@app.route("/inc")
def inc():
	if 'n' not in session:
		session['n'] = 0
	session['n'] = session['n'] + 1
	return render_template("counter.html")

@app.route("/dec")
def dec():
	if 'n' not in session:
		session['n'] = 0
	session['n'] = session['n'] - 1
	return render_template("counter.html")

@app.route("/reset")
def reset():
	session['n']=0
	#return redirect("/inc")
	return redirect(url_for('inc'))

@app.route("/")
def index():
	return "hello"

if __name__ == "__main__":
	app.debug = True
	app.secret_key="Don't store this on Github"
	app.run(host='0.0.0.0', port=8000)
