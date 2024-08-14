import PyIKG2p

g2p = PyIKG2p.ChineseG2p("mandarin")


def test_main():
    raw = "测试"
    res = g2p.hanzi_to_pinyin(raw, False, False, PyIKG2p.ErrorType.Default)
    res = [x.syllable for x in res]
    print(res)


if __name__ == "__main__":
    test_main()
