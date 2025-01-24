/* Inline GDB pretty printer for result
(C) 2024 Niall Douglas <http://www.nedproductions.biz/> (6 commits)
File Created: Jun 2024


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BOOST_OUTCOME_INLINE_GDB_PRETTY_PRINTER_H
#define BOOST_OUTCOME_INLINE_GDB_PRETTY_PRINTER_H

#ifndef BOOST_OUTCOME_DISABLE_INLINE_GDB_PRETTY_PRINTERS
#if defined(__ELF__)
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverlength-strings"
#endif
__asm__(".pushsection \".debug_gdb_scripts\", \"MS\",@progbits,1\n"
        ".byte 4 /* Python Text */\n"
        ".ascii \"gdb.inlined-script\\n\"\n"
        ".ascii \"import gdb.printing\\n\"\n"
        ".ascii \"import os\\n\"\n"

        ".ascii \"def synthesise_gdb_value_from_string(s):\\n\"\n"
        ".ascii \"    '''For when you want to return a synthetic string from children()'''\\n\"\n"
        ".ascii \"    return gdb.Value(s + '\\0').cast(gdb.lookup_type('char').pointer())\\n\"\n"

        ".ascii \"class OutcomeBasicOutcomePrinter(object):\\n\"\n"
        ".ascii \"    '''Print an outcome::basic_outcome<T> and outcome::basic_result<T>'''\\n\"\n"

        ".ascii \"    def __init__(self, val):\\n\"\n"
        ".ascii \"        self.val = val\\n\"\n"

        ".ascii \"    def children(self):\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 1 == 1:\\n\"\n"
        ".ascii \"            yield ('value', self.val['_state']['_value'])\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 2 == 2:\\n\"\n"
        ".ascii \"            yield ('error', self.val['_state']['_error'])\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 4 == 4:\\n\"\n"
        ".ascii \"            yield ('exception', self.val['_ptr'])\\n\"\n"

        ".ascii \"    def display_hint(self):\\n\"\n"
        ".ascii \"        return None\\n\"\n"

        ".ascii \"    def to_string(self):\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 54 == 54:\\n\"\n"
        ".ascii \"            return 'errored (errno, moved from) + exceptioned'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 50 == 50:\\n\"\n"
        ".ascii \"            return 'errored (errno, moved from)'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 38 == 38:\\n\"\n"
        ".ascii \"            return 'errored + exceptioned (moved from)'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 36 == 36:\\n\"\n"
        ".ascii \"            return 'exceptioned (moved from)'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 35 == 35:\\n\"\n"
        ".ascii \"            return 'errored (moved from)'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 33 == 33:\\n\"\n"
        ".ascii \"            return 'valued (moved from)'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 22 == 22:\\n\"\n"
        ".ascii \"            return 'errored (errno) + exceptioned'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 18 == 18:\\n\"\n"
        ".ascii \"            return 'errored (errno)'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 6 == 6:\\n\"\n"
        ".ascii \"            return 'errored + exceptioned'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 4 == 4:\\n\"\n"
        ".ascii \"            return 'exceptioned'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 2 == 2:\\n\"\n"
        ".ascii \"            return 'errored'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 1 == 1:\\n\"\n"
        ".ascii \"            return 'valued'\\n\"\n"
        ".ascii \"        if self.val['_state']['_status']['status_value'] & 0xff == 0:\\n\"\n"
        ".ascii \"            return 'empty'\\n\"\n"

        ".ascii \"class OutcomeCResultStatusPrinter(object):\\n\"\n"
        ".ascii \"    '''Print a C result'''\\n\"\n"

        ".ascii \"    def __init__(self, val):\\n\"\n"
        ".ascii \"        self.val = val\\n\"\n"

        ".ascii \"    def children(self):\\n\"\n"
        ".ascii \"        if self.val['flags'] & 1 == 1:\\n\"\n"
        ".ascii \"            yield ('value', self.val['value'])\\n\"\n"
        ".ascii \"        if self.val['flags'] & 2 == 2:\\n\"\n"
        ".ascii \"            yield ('error', self.val['error'])\\n\"\n"

        ".ascii \"    def display_hint(self):\\n\"\n"
        ".ascii \"        return None\\n\"\n"

        ".ascii \"    def to_string(self):\\n\"\n"
        ".ascii \"        if self.val['flags'] & 50 == 50:\\n\"\n"
        ".ascii \"            return 'errored (errno, moved from)'\\n\"\n"
        ".ascii \"        if self.val['flags'] & 35 == 35:\\n\"\n"
        ".ascii \"            return 'errored (moved from)'\\n\"\n"
        ".ascii \"        if self.val['flags'] & 33 == 33:\\n\"\n"
        ".ascii \"            return 'valued (moved from)'\\n\"\n"
        ".ascii \"        if self.val['flags'] & 18 == 18:\\n\"\n"
        ".ascii \"            return 'errored (errno)'\\n\"\n"
        ".ascii \"        if self.val['flags'] & 2 == 2:\\n\"\n"
        ".ascii \"            return 'errored'\\n\"\n"
        ".ascii \"        if self.val['flags'] & 1 == 1:\\n\"\n"
        ".ascii \"            return 'valued'\\n\"\n"
        ".ascii \"        if self.val['flags'] & 0xff == 0:\\n\"\n"
        ".ascii \"            return 'empty'\\n\"\n"


        ".ascii \"class OutcomeCStatusCodePrinter(object):\\n\"\n"
        ".ascii \"    '''Print a C status code'''\\n\"\n"

        ".ascii \"    def __init__(self, val):\\n\"\n"
        ".ascii \"        self.val = val\\n\"\n"

        ".ascii \"    def children(self):\\n\"\n"
        ".ascii \"        yield ('domain', self.val['domain'])\\n\"\n"
        ".ascii \"        yield ('value', self.val['value'])\\n\"\n"

        ".ascii \"    def display_hint(self):\\n\"\n"
        ".ascii \"        return None\\n\"\n"

        ".ascii \"    def to_string(self):\\n\"\n"
        ".ascii \"        s = str(self.val['domain'])\\n\"\n"
        ".ascii \"        if 'posix_code_domain' in s or 'generic_code_domain' in s:\\n\"\n"
        ".ascii \"            return str(self.val['value']) + ' (' + os.strerror(int(self.val['value'])) + ')'\\n\"\n"
        ".ascii \"        else:\\n\"\n"
        ".ascii \"            return self.val['value']\\n\"\n"

        ".ascii \"def build_pretty_printer():\\n\"\n"
        ".ascii \"    pp = gdb.printing.RegexpCollectionPrettyPrinter('outcome_v2')\\n\"\n"
        ".ascii \"    pp.add_printer('outcome_v2::basic_result', '^(boost::)?outcome_v2[_0-9a-f]*::basic_result<.*>$', OutcomeBasicOutcomePrinter)\\n\"\n"
        ".ascii \"    pp.add_printer('outcome_v2::basic_outcome', '^(boost::)?outcome_v2[_0-9a-f]*::basic_outcome<.*>$', OutcomeBasicOutcomePrinter)\\n\"\n"
        ".ascii \"    pp.add_printer('cxx_result_status_code_*', '^cxx_result_status_code_.*$', OutcomeCResultStatusPrinter)\\n\"\n"
        ".ascii \"    pp.add_printer('cxx_status_code_*', '^cxx_status_code_.*$', OutcomeCStatusCodePrinter)\\n\"\n"
        ".ascii \"    return pp\\n\"\n"

        ".ascii \"def register_printers(obj = None):\\n\"\n"
        ".ascii \"    gdb.printing.register_pretty_printer(obj, build_pretty_printer(), replace = True)\\n\"\n"

        ".ascii \"register_printers(gdb.current_objfile())\\n\"\n"

        ".byte 0\n"
        ".popsection\n");
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif
#endif

#endif
