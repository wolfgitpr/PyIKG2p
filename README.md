# IkG2p

## Intro

IKg2p module generated with Pybind11

## Install

```
pip install .
```

## Usage

```python
    import PyIKG2p

    g2p = PyIKG2p.ChineseG2p("mandarin")
    res = g2p.hanzi_to_pinyin("测试", False, False, PyIKG2p.ErrorType.Default)
    res = [x.syllable for x in res]
```