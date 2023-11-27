# builds src files
import platform
import subprocess


def build_src():
    if platform.system() == "Windows":
        subprocess.call(["external/premake/premake5.exe", "vs2022"])
    else:
        print("Windows is currently only supported. \nSorry :(")


if __name__ == "__main__":
    build_src()
