import os
import json
import requests

if __name__ == "__main__":
    pulls = ["backgrounds",
             "classes",
             "equipment-categories/armor",
             "equipment-categories/weapon",
             "races",
             "subclasses"]

    gets = {}

    for item in pulls:
        with requests.get("https://www.dnd5eapi.co/api/" + item) as jsonurl:
            gets[item] = jsonurl.json()

    for item in gets:
        if not os.path.exists(item):
            os.makedirs(item)

        with open(item + "/" + item.split("/")[-1] + ".json", "w") as super_f:
            super_f.write(json.dumps(gets[item]))

        for it in gets[item]["equipment" if "equipment" in gets[item] else "results"]:
            if "url" in it:
                with requests.get("https://www.dnd5eapi.co" + it["url"]) as jsonurl:
                    with open(item + "/" + jsonurl.json()["index"] + ".json", "w") as f:
                        f.write(json.dumps(jsonurl.json()))
