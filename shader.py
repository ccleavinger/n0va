# builds shaders
import os
import platform
import subprocess


def build_shaders():
    VULKAN_PATH = os.environ['VULKAN_SDK']

    glslc = ""

    if platform.system() == "Windows":
        glslc = f"{VULKAN_PATH}\\Bin\\glslc.exe"
    else:
        raise Exception("Unsupported platform!")

    for file in os.listdir(os.fsencode("Nova/shaders")):
        filename = os.fsdecode(file)

        if not filename.endswith(".spv"):
            subprocess.call([glslc, filename, '-o', f"{filename}.spv"])


if __name__ == "__main__":
    build_shaders()
