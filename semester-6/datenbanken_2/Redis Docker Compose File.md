```yaml
services:
	redis:
		image: redis:latest
		container_name: redis
		ports:
			- 6379:6379
	  
```


> [!hint] Therre exists a Hardened Docker image for redis - useful for production use.