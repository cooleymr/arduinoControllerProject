import subprocess

def open_url(url):
    subprocess.run(["open", "-a", "Safari", url])

if __name__ == '__main__':
    open_url("https://iu.instructure.com/courses/2120891")