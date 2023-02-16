import subprocess

def open_discord():
    subprocess.run(["open", "-a", "Slack"])

if __name__ == '__main__':
    open_discord()
