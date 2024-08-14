#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "MandarinG2p.h"
#include "G2pglobal.h"
#include "G2pRes.h"

namespace py = pybind11;

PYBIND11_MODULE(PyIKG2p, m)
{
    m.doc() = "IKg2p module generated with Pybind11";
    m.def("dictionaryPath", &IKg2p::dictionaryPath, pybind11::return_value_policy::reference);
    m.def("setDictionaryPath", &IKg2p::setDictionaryPath, py::arg("dir"));

    py::class_<IKg2p::G2pRes>(m, "G2pRes")
        .def(py::init<>())
        .def_readwrite("lyric", &IKg2p::G2pRes::lyric)
        .def_readwrite("syllable", &IKg2p::G2pRes::syllable)
        .def_readwrite("candidates", &IKg2p::G2pRes::candidates)
        .def_readwrite("error", &IKg2p::G2pRes::error);

    py::enum_<IKg2p::errorType>(m, "ErrorType")
        .value("Default", IKg2p::errorType::Default)
        .value("Ignore", IKg2p::errorType::Ignore);

    py::class_<IKg2p::ChineseG2p>(m, "ChineseG2p")
        .def(py::init<const std::string&>())
        .def("initialized", &IKg2p::ChineseG2p::initialized)
        .def("hanzi_to_pinyin",
             py::overload_cast<const std::string&, bool, bool, IKg2p::errorType>(
                 &IKg2p::ChineseG2p::hanziToPinyin, py::const_),
             py::arg("input"), py::arg("tone") = true, py::arg("convertNum") = true,
             py::arg("error") = IKg2p::errorType::Default)
        .def("hanzi_list_to_pinyin",
             py::overload_cast<const std::vector<std::string>&, bool, bool, IKg2p::errorType>(
                 &IKg2p::ChineseG2p::hanziToPinyin, py::const_),
             py::arg("input"), py::arg("tone") = true, py::arg("convertNum") = true,
             py::arg("error") = IKg2p::errorType::Default)
        .def_static("res_to_string_list", &IKg2p::ChineseG2p::resToStringList)
        .def("trad_to_sim", &IKg2p::ChineseG2p::tradToSim)
        .def("is_polyphonic", &IKg2p::ChineseG2p::isPolyphonic)
        .def("get_default_pinyin", &IKg2p::ChineseG2p::getDefaultPinyin, py::arg("text"), py::arg("tone") = true);
}
