import sys


def template(md_name):
    file_name = md_name + ".md"
    md_title = "# " + md_name + "\n"
    md_path = "./" + file_name

    with open("./template.md", 'r') as f:
        md_body = f.read()

    with open(md_path, 'w') as f:
        f.write(md_title)
        f.write(md_body)

    print('generate file: ', md_path)

    
if __name__ == "__main__":
    
    # parser args.
    script_name = sys.argv[0]
    if len(sys.argv) > 1:
        file_name = sys.argv[1]
    else:
        file_name = "file_name"
    # generate markdown note.
    template(file_name)

