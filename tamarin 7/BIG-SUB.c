static char* sub(char* a, char* b) {




		int len1, len2, temp;

		bool cond = false;

		len1 = strlen(a);
		len2 = strlen(b);

		if (len2 > len1) {


			char* temp = a;
			a = b;
			b = temp;
			int tmp = len2;
			len2 = len1;
			len1 = tmp;
		}
		if (len2 == len1) {
			for (int p = 0; p < len1; p++) {
				if (a[p] == b[p]) {
					continue;
				}
				else if (a[p] < b[p]) {
					char* temp = a;
					a = b;
					b = temp;
					int tmp = len2;
					len2 = len1;
					len1 = tmp;
					break;
				}
				else
					break;

			}

		}


		char* ans = new char[len1 + 2];


		if (!strcmp(a, b)) {
			ans[0] = '0';
			ans[1] = '\0';

			return ans;
		}
		else {
			ans[len1] = '\0';
			for (int n = len1 - 1, m = len2 - 1; n >= 0; n--, m--) {
				if (m >= 0) {
					temp = a[n] - b[m];
					if (cond) {
						temp -= 1;
						cond = false;
					}
					if (temp >= 0) {
						ans[n] = temp + '0';
					}
					else {
						cond = true;
						temp += 10;
						ans[n] = temp + '0';
					}
				}
				else {
					if (cond) {
						temp = a[n] - 1 - '0';
						cond = false;
						if (temp < 0) {
							cond = true;
							temp += 10;

						}
						ans[n] = temp + '0';

					}
					else {
						ans[n] = a[n];
					}

				}
			}





			ans[len1] = '\0';
			while (ans[0] - '0' == 0) {
				for (int k = 0; k < len1; k++) {
					ans[k] = ans[k + 1];

				}
			}

		}


		return ans;
	}
