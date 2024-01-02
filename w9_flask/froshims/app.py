from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)
db = SQL("sqlite:///froshims.db")

# REGISTRANTS = {} # {} means dictionary
SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports = SPORTS) # 表模板中的 sports 等同於此處的 SPORTS

@app.route("/deregister", methods=["POST"])
def deregister():

    # Forget registrant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():
    # validate name & sport
    name = request.form.get("name")
    sport = request.form.get("sport")
    # validate submission
    if not name or sport not in SPORTS:
        return render_template("failure.html" )

    # Remember registrants
    # 關聯某 name 與某 sport，儲存在 REGISTRANTS (字典) 中
    # REGISTRANTS[name] = sport
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
    # Confirm registration
    return redirect("/registrants") # 必須要引入 redirect 才會起作用

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    # return render_template("registrants.html", registrants=REGISTRANTS) # 表模板中的 registrants 等同於此處的 REGISTRANTS
    return render_template("registrants.html", registrants=registrants)
