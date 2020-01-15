package ro.ubbcluj.cs.questions.client.service;

import org.apache.http.HttpHost;
import org.apache.http.auth.AuthScope;
import org.apache.http.auth.UsernamePasswordCredentials;
import org.apache.http.client.AuthCache;
import org.apache.http.client.protocol.HttpClientContext;
import org.apache.http.impl.auth.BasicScheme;
import org.apache.http.impl.client.BasicAuthCache;
import org.apache.http.impl.client.BasicCredentialsProvider;
import org.apache.http.protocol.HttpContext;
import org.springframework.http.HttpMethod;
import org.springframework.http.client.HttpComponentsClientHttpRequestFactory;
import ro.ubbcluj.cs.questions.common.model.User;

import java.net.URI;

public class AuthHttpComponentsClientHttpRequestFactory extends
        HttpComponentsClientHttpRequestFactory {

    private HttpHost host;
    private User user;

    public AuthHttpComponentsClientHttpRequestFactory(HttpHost host, User user) {
        super();
        this.host = host;
        this.user = user;
    }

    @Override
    protected HttpContext createHttpContext(HttpMethod httpMethod, URI uri) {
        // Create AuthCache instance
        AuthCache authCache = new BasicAuthCache();
        // Generate BASIC scheme object and add it to the local auth cache
        BasicScheme basicAuth = new BasicScheme();
        authCache.put(host, basicAuth);

        // Add AuthCache to the execution context
        HttpClientContext localcontext = HttpClientContext.create();
        localcontext.setAuthCache(authCache);

        if (user != null) {
            BasicCredentialsProvider credsProvider = new BasicCredentialsProvider();
            credsProvider.setCredentials(new AuthScope(host), new UsernamePasswordCredentials(user.getUsername(), user.getPassword()));
            localcontext.setCredentialsProvider(credsProvider);
        }
        return localcontext;
    }

    public void setUser(User user) {
        this.user = user;
    }
}
