import subprocess

def make_call(number):
    subprocess.call(["/usr/bin/open", "-W", "-n", "-a", "/System/Applications/Facetime.app",
                 "tel://{}".format(number)])
    

if __name__ == '__main__':
    make_call("3174414292") # Phone number beign called