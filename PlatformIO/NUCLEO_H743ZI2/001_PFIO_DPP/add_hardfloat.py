Import( "env" )

flags = [
    "-u _printf_float",
    "-mfpu=fpv5-d16",
    "-mfloat-abi=hard",
    "-mthumb",
]
env.Append(CCFLAGS=flags, LINKFLAGS=flags, ASFLAGS=flags)