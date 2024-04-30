from typing import List


class Solution:
    def topStudents(
        self,
        positive_feedback: List[str],
        negative_feedback: List[str],
        report: List[str],
        student_id: List[int],
        k: int,
    ) -> List[int]:
        PF = set(positive_feedback)
        NF = set(negative_feedback)

        def get_score(x: str):
            xs = x.split()
            S = 0
            for x in xs:
                if x in PF:
                    S += 3
                if x in NF:
                    S -= 1
            return S

        student_score = list(map(get_score, report))

        def key(id: int):
            return (-student_score[id], student_id[id])

        n = len(student_id)
        index = list(range(n))
        index.sort(key=key)
        # for i in index:
        #     print(student_id[i], student_score[i])
        ret = [0] * k
        for i in range(k):
            ret[i] = student_id[index[i]]
        return ret


sol = Solution()
# r = sol.topStudents(
#     ["smart","brilliant","studious"],
#     ["not"],
#     ["this student is studious","the student is smart"],
#     [1, 2],
#     2,
# )

# r = sol.topStudents(
#     ["smart","brilliant","studious"],
#     ["not"],
#     ["this student is not studious","the student is smart"],
#     [1, 2],
#     2
# )

# r = sol.topStudents(
#     ["fkeofjpc", "qq", "iio"],
#     ["jdh", "khj", "eget", "rjstbhe", "yzyoatfyx", "wlinrrgcm"],
#     [
#         "rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio",
#         "gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx",
#         "tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe",
#         "jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh",
#         "yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq",
#         "fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v",
#         "wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq",
#         "d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe",
#     ],
#     [
#         96537918,
#         589204657,
#         765963609,
#         613766496,
#         43871615,
#         189209587,
#         239084671,
#         908938263,
#     ],
#     3,
# )

# x = input()
import sys
x = sys.stdin.readline()
print(f'"{x}"')
