#
# SConscript
#
# Copyright (c) 2014 Jeremy Garff <jer @ jers.net>
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted
# provided that the following conditions are met:
#
#     1.  Redistributions of source code must retain the above copyright notice, this list of
#         conditions and the following disclaimer.
#     2.  Redistributions in binary form must reproduce the above copyright notice, this list
#         of conditions and the following disclaimer in the documentation and/or other materials
#         provided with the distribution.
#     3.  Neither the name of the owner nor the names of its contributors may be used to endorse
#         or promote products derived from this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
# FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
# OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
# OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# Build Library
lib_srcs = Split('''
    ws2811.c
    pwm.c
    dma.c
    board_info.c
    mailbox.c
''')

libs = [];

ws2811_lib = Library('libws2811', lib_srcs)
libs.append(ws2811_lib)

ws2811_dll = SharedLibrary('ws2811', lib_srcs)

# Test Program
main_srcs = Split('''
    main.c
''')

objs = []
for src in main_srcs:
   objs.append(Object(src))

test = Program('test', objs + libs)

# Clear program
clear_srcs = Split('''
	clear.c
''')

objs = []
for src in clear_srcs:
	objs.append(Object(src))
clear = Program('clear', objs + libs)

# dlltest program
dlltest_srcs = Split('''
	dlltest.c
''')

objs = []
for src in dlltest_srcs:
	objs.append(Object(src))
dlltest = Program('dlltest', objs, LIBS = ['ws2811'], LIBPATH = ['.']);

# Build everything
Default([test, clear, ws2811_lib, ws2811_dll])